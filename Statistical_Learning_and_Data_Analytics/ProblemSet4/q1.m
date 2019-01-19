load("ps4q1.mat");

% Centralize
for i = (1:2)
    data(:,i) = data(:,i) - mean(data(:,i));
end

% Standardize
for i = (1:2)
    data(:,i) = data(:,i) / std(data(:,i));
end
% 
% figure;
% scatter(data(:,1),data(:,2), 'filled');
% title("Plot of data");
% xlabel("x1");
% ylabel("x2");

% Parameters
K = 3;
means = [-1,1;1,-1;0,-1];
norm = "l2";

% Clustering
[means, classes] = k_means_clustering(K, data, means, norm);

% Plot the results
plot_clusters(data, classes, K, means, "Step 4");

% K-Means Clustering
function [result_means, result_classes] = k_means_clustering(K, data, means, norm)
    for e = (1:100)
        temp = means;
        
        % Expectation
        classes = zeros(length(data),1);
        for i = (1:length(data))
            loss_i = zeros(1,K);
            for j = (1:K)
                points = [data(i,:);means(j,:)];
                loss_i(j) = loss(points, norm);
            end
            indexes = find(loss_i == min(loss_i(:)));
            classes(i) = indexes(1);
        end
        
        figure;
        plot_clusters(data, classes, K, means, char(cellstr(num2str(e, 'Step %d'))));
        
        % Maximization
        for i = (1:K)
            means(i,:) = mean(data((classes(:) == i),:));
        end
        
        if means == temp
            break
        end
    end
    e
    result_classes = classes;
    result_means = means;
end

% Distance Function
function distance = loss(points, form)
    if form == "l1"
        distance = pdist(points,'euclidean');
    elseif form == "l2"
        distance = pdist(points,'minkowski', 1);
    end
end

% Plots the data points with clusters
function plot_clusters(data, classes, K, means, p_title)
    colors = ['b', 'r', 'g', 'y', 'k', 'c', 'm'];
    for i = (1:K)
        title(p_title);
        xlabel("x1");
        ylabel("x2");
        scatter(data((classes == i),1), data((classes == i),2), length(data), colors(mod(i,7)), '.')
        hold on;
        scatter(means(i,1), means(i,2), 150, 'k', 'x')
        hold on;
    end
end