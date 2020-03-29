import numpy as np
import pandas as pd
np.warnings.filterwarnings('ignore')

# Load the dataset
test_feature = pd.read_csv("question-4-test-features.csv", header=None)
test_label = pd.read_csv("question-4-test-labels.csv", header=None)
train_feature = pd.read_csv("question-4-train-features.csv", header=None)
train_label = pd.read_csv("question-4-train-labels.csv", header=None)
labels = ["negative", "neutral", "positive"]

# Concatinated training data for multinomial and bernoulli
train_multinomial = pd.concat((train_feature, train_label[0].rename("label")), axis=1)
train_bernoulli = train_feature.copy()
train_bernoulli[train_bernoulli != 0] = 1
train_bernoulli = pd.concat((train_bernoulli, train_label[0].rename("label")), axis=1)

# Vocab is read
with open('question-4-vocab.txt', 'r', encoding="utf-8") as f:
    lines = f.readlines()
words = [word.split("\t")[0] for word in lines]
counts = [int(word.split("\t")[1][:-1]) for word in lines]

# Safe divide


def div(x, y):
    if y == 0:
        return 0
    return x / y

# Calculate the P(Y = yk) for each class
prior = [0, 0, 0]
label_counts = train_label[0].value_counts()
prior[0] = np.log(div(label_counts[0], len(train_feature)))  # negative
prior[1] = np.log(div(label_counts[1], len(train_feature)))  # neutral
prior[2] = np.log(div(label_counts[2], len(train_feature)))  # positive

# Total word counts in each class of documents
negative_words = train_multinomial.groupby("label").sum().sum(axis=1)[0]
neutral_words = train_multinomial.groupby("label").sum().sum(axis=1)[1]
positive_words = train_multinomial.groupby("label").sum().sum(axis=1)[2]


##########################################################################
###########################    MLE    ####################################
##########################################################################

# P(Xj | Y = yk) for each word Xj and each class yk, log is taken
pr_words_mle = np.full((len(words), 3), 0, dtype=float)

for i in range(len(words)):
    occurences = train_multinomial.iloc[:, [i, len(words)]].groupby("label").sum()[i]
    pr_words_mle[i][0] = np.log(div(occurences[0], negative_words))  # negative
    pr_words_mle[i][1] = np.log(div(occurences[1], neutral_words))  # neutral
    pr_words_mle[i][2] = np.log(div(occurences[2], positive_words))  # positive

# Calculate prediction values
pr_words_mle = np.nan_to_num(pr_words_mle)
results_mle = np.dot(test_feature, pr_words_mle) + np.array(prior)

# Fix the too big/small values
results_mle[results_mle > 1e100] = np.inf
results_mle[results_mle < -1e100] = -np.inf

# Predict
prediction_values = np.amax(results_mle, axis=1)
candidates = []
for i in range(len(prediction_values)):
    candidates.append(np.where(results_mle[i] == prediction_values[i])[0])
candidates = np.array(candidates)

predicted_mle = np.ones(np.shape(candidates), dtype=object)

for i in range(len(candidates)):
    if len(candidates[i]) > 1:  # tie
        predicted_mle[i] = labels[1]
    else:
        predicted_mle[i] = labels[candidates[i][0]]

# Accuracy
accuracy_mle = np.sum(predicted_mle == test_label[0].values) / len(test_label)
print("MLE accuracy: " + str(accuracy_mle))


##########################################################################
###########################    MAP    ####################################
##########################################################################

# P(Xj | Y = yk) for each word Xj and each class yk, log is taken, alpha=1
pr_words_map = np.full((len(words), 3), 0, dtype=float)

for i in range(len(words)):
    occurences = train_multinomial.iloc[:, [i, len(words)]].groupby("label").sum()[i]
    pr_words_map[i][0] = np.log(div(occurences[0] + 1, negative_words + len(words)))  # negative
    pr_words_map[i][1] = np.log(div(occurences[1] + 1, neutral_words + len(words)))  # neutral
    pr_words_map[i][2] = np.log(div(occurences[2] + 1, positive_words + len(words)))  # positive

# Calculate prediction values
pr_words_map = np.nan_to_num(pr_words_map)
results_map = np.dot(test_feature, pr_words_map) + np.array(prior)

# Fix the too big/small values
results_map[results_map > 1e100] = np.inf
results_map[results_map < -1e100] = -np.inf

# Predict
prediction_values = np.amax(results_map, axis=1)

candidates = []
for i in range(len(prediction_values)):
    candidates.append(np.where(results_map[i] == prediction_values[i])[0])
candidates = np.array(candidates)

predicted_map = np.ones(len(candidates), dtype=object)

for i in range(len(candidates)):
    if len(candidates[i]) > 1:  # tie
        predicted_map[i] = labels[1]
    else:
        predicted_map[i] = labels[candidates[i][0]]

# Accuracy
accuracy_map = np.sum(predicted_map == test_label[0].values) / len(test_label)
print("MAP accuracy: " + str(accuracy_map))


##########################################################################
##########################   Bernoulli  ##################################
##########################################################################

# P(Xj | Y = yk) for each word Xj and each class yk, log is taken, alpha=1
pr_words = np.full((len(words), 3), 0, dtype=float)

for i in range(len(words)):
    occurences = train_bernoulli.iloc[:, [i, len(words)]].groupby("label").sum()[i]
    pr_words[i][0] = div(occurences[0], label_counts[0])  # negative
    pr_words[i][1] = div(occurences[1], label_counts[1])  # neutral
    pr_words[i][2] = div(occurences[2], label_counts[2])  # positive

# Calculate prediction values
pr_words_comp = np.array(1) - pr_words
test_feature_comp = np.array(1) - test_feature

neg = test_feature * np.transpose(pr_words)[0] + test_feature_comp * np.transpose(pr_words_comp)[0]
neu = test_feature * np.transpose(pr_words)[1] + test_feature_comp * np.transpose(pr_words_comp)[1]
pos = test_feature * np.transpose(pr_words)[2] + test_feature_comp * np.transpose(pr_words_comp)[2]

results_ber = np.transpose([np.sum(np.log(neg), axis=1), np.sum(np.log(neu), axis=1), np.sum(np.log(pos), axis=1)]) + np.array(prior)

# Predict
prediction_values = np.amax(results_ber, axis=1)
candidates = []
for i in range(len(prediction_values)):
    candidates.append(np.where(results_ber[i] == prediction_values[i])[0])
candidates = np.array(candidates)

predicted_ber = np.ones(np.shape(candidates), dtype=object)
for i in range(len(candidates)):
    if len(candidates[i]) > 1:  # tie
        predicted_ber[i] = labels[1]
    else:
        predicted_ber[i] = labels[candidates[i][0]]

# Accuracy
accuracy_ber = np.sum(predicted_ber == test_label[0].values) / len(test_label)
print("Bernoulli accuracy: " + str(accuracy_ber))


# Find most common words
words = np.array([word.split("\t")[0] for word in lines])
counts = np.array([int(word.split("\t")[1][:-1]) for word in lines])

dataset = pd.DataFrame({'word': words, 'count': list(counts)}, columns=['word', 'count'])


common_ones = list(dataset.sort_values("count", ascending=False)[0:20]["word"])
print("Most common 20 words:")
for i in common_ones:
    print(i)
