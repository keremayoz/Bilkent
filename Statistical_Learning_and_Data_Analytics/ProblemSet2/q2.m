M = csvread('student.csv');

%Response
y = M(:,1);

%Predictor
x = ones(length(y),2);
x(:,2) = M(:,2);

mean_of_data = mean(x);
std_of_data = std(x);

x = (x-mean(x))./std(x);
x(isnan(x)) = 1;

%Initialize beta
beta = rand(1,2);

gama = 0.001;
error = zeros(1,100);
prev_error = 0;

for ind = 1:100
    i = mod(ind,length(y)) + 1;
    fi = 1 - sigmf(x * transpose(beta),[1,0]);
    change = transpose(transpose(x) * (fi-y));
    error(ind) = calculate_mse_error((1-sigmf(x * transpose(beta),[1,0])), y);
    if abs(error(ind) - prev_error) < 0.001
        break
    end
    beta = beta + gama * change;
    prev_error = error(ind);
end

x_try = 0:800;
x_try = (x_try-mean(x(:,2))./std(x(:,2)));
x_try = horzcat(ones(801,1),transpose(x_try));
x_try(:,2) = (x_try(:,2) - mean_of_data) / std_of_data;

result = zeros(1,801);
result = (1-sigmf(x_try * transpose(beta),[1,0]));

figure;
plot(1:801,result);
hold on;
title("Pr(Y = 1 | X = x)");
ylabel("Probability");
xlabel("X");

function error = calculate_mse_error(y_pred, y)
    error = 0;
    for i = [1:length(y)]
        error = error + (y_pred(i) - y(i)) * (y_pred(i) - y(i));
    end
    error = error ./ length(y);
end