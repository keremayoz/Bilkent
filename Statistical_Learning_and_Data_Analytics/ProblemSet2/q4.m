test = load('PS2Q4.mat');

%Response
y = y_tr;

%Predictor
x = ones(length(y),2);
x(:,2) = x_tr;

x = (x-mean(x))./std(x);
x(isnan(x)) = 1;

%Initialize beta
beta = rand(1,2);

gama = 0.1;

error = zeros(1,100);

for i = 1:1
    gradient = 0;
    
    for j = [1:1000]
        gradient = gradient - y(i) * x(i) + exp(x(i) * beta)* x(i);
    end
    gradient = gradient ./1000;
    
    beta = beta - gama * gradient;
    
    y_pred = zeros(length(y),1);
    for k = [1:1000]
        y_pred(k) = pdf('Poisson',exp(x(k,:) * transpose(beta)),k);
    end

    error(i) = calculate_mse_error(y_pred, y);
end

figure;
plot(1:100,error);
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