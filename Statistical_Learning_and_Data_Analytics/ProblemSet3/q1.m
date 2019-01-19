load("perceptrontest.mat");

x = D(:,1:11);
y = D(:,12);

[weights, mistakes] = train_perceptron(x,y,1,5000);
error = calculate_error(x,weights,y);
plot(mistakes);
title("Total Number of Mistakes");
ylabel("Number of Mistakes");
xlabel("Iteration Count");

function error = calculate_error(x,w,y)
    error = 0; 
    for i = (1:length(x))
        est = perceptron(x(i,:),w);
        error = error + (y(i,:) - est);
    end
end

function [weig, mistakes] = train_perceptron(x,y,learning_rate,iteration_count)
    w = zeros(1,11);
    mistakes = zeros(1,5000);
    for i = (1:iteration_count)
       [w, mistakes(i)] = single_iteration(x,y,learning_rate,w);
    end
    weig = w;
end

function [weigh, mistake] = single_iteration(x, y, learning_rate, w)
    mistake = 0;
    for i = (1:length(x))
        est = perceptron(x(i,:),w);
        w = w + learning_rate * (y(i,:) - est) * x(i,:);
        mistake = mistake + abs(y(i,:) - est);
    end
    weigh = w;
end


function estimate = perceptron(x_i,w)
    res = x_i*transpose(w);
    if res > 0
        estimate = 1;
    else
        estimate = 0;
    end
end

% weights =
% 
%    57.0000   29.2284  231.6887 -201.7355 -115.8199 -174.0012  -57.7855  231.6201   87.1270 -115.8210  -86.5900
% 
% 
% error =
% 
%      0
