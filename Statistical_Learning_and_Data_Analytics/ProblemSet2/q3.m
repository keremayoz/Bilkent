%Preperation
train = load('PS2Q3train.mat');
test = load('PS2Q3test.mat');

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%      OLS     %%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
ols_train_error = zeros(1,10);
ols_test_error = zeros(1,10);

for p = [0:10]
    %Train
    x_train = create_polynomial(x_tr,p);
    beta = (inv(transpose(x_train)*x_train))*transpose(x_train)*y_tr;
    y_pred = x_train * beta;
    
    %Test
    x_test = create_polynomial(x_te,p);
    y_tested = x_test * beta;
    
    %Calculate errors
    ols_train_error(p+1) = calculate_error(y_pred,y_tr);
    ols_test_error(p+1) = calculate_error(y_tested,y_te);
end

optimal_p = find(ols_test_error == min(ols_test_error(:)));

figure;
plot(0:10,ols_train_error);
hold on;
plot(0:10,ols_test_error);
title("Test Error vs Train error with OLS");
legend("Train Error","Test Error");
ylabel("Error");
xlabel("p");
optimal_p = 5;
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%     RIDGE     %%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
ridge_train_error = zeros(1,101);
ridge_test_error = zeros(1,101);

%Built polynomials
x_train = create_polynomial(x_tr,optimal_p);
x_test = create_polynomial(x_te,optimal_p);

%Normalize input data, bias is equal to NAN in that case
x_train = (x_train-mean(x_train))./std(x_train);
x_train(isnan(x_train)) = 1;

x_test = (x_test-mean(x_test))./std(x_test);
x_test(isnan(x_test)) = 1;

y_tr = (y_tr-mean(y_tr));
y_te = (y_te-mean(y_te));

for lambda = [1:100]
    %Train and Test
    beta = (inv(transpose(x_train)*x_train + lambda .* eye(size(x_train,2))))*transpose(x_train)*y_tr;
    y_pred = x_train * beta;
    y_tested = x_test * beta;
    
    %Calculate errors
    ridge_train_error(lambda+1) = calculate_error(y_pred,y_tr);
    ridge_test_error(lambda+1) = calculate_error(y_tested,y_te);
end

ridge_train_error(1) = ols_train_error(optimal_p);
ridge_test_error(1) = ols_test_error(optimal_p);

figure;
plot(0:100,ridge_train_error);
hold on;
plot(0:100,ridge_test_error);
title("Test Error vs Train error with Ridge");
legend("Train Error","Test Error");
ylabel("Error");
xlabel("Lambda");

disp("Hello")
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%     LASSO     %%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
lasso_train_error = zeros(1,101);
lasso_test_error = zeros(1,101);

%Built polynomials
x_train = create_polynomial(x_tr,optimal_p);
x_test = create_polynomial(x_te,optimal_p);

%Normalize input data, bias is equal to NAN in that case
x_train = (x_train-mean(x_train))./std(x_train);
x_train(isnan(x_train)) = 1;

x_test = (x_test-mean(x_test))./std(x_test);
x_test(isnan(x_test)) = 1;

y_tr = (y_tr-mean(y_tr));
y_te = (y_te-mean(y_te));

for lambda = [1:100]
    %Train and Test
    beta = lasso(x_train,y_tr,'NumLambda',lambda);
    
    y_pred = x_train * beta;
    y_tested = x_test * beta;
    
    %Calculate errors
    lasso_train_error(lambda+1) = calculate_error(y_pred,y_tr);
    lasso_test_error(lambda+1) = calculate_error(y_tested,y_te);

end

lasso_train_error(1) = ols_train_error(optimal_p);
lasso_test_error(1) = ols_test_error(optimal_p);

figure;
plot(0:100,lasso_train_error);
hold on;
plot(0:100,lasso_test_error);
title("Test Error vs Train error with Lasso");
legend("Train Error","Test Error");
ylabel("Error");
xlabel("Lambda");
beta
disp("Hello")

function x_poly = create_polynomial(x, p)
    x_poly = ones(length(x),1);
    for i = 1:p
        x_p = x.^i;
        x_poly =  horzcat(x_poly,x_p); 
    end
end

function error = calculate_error(y_pred, y)
    error = 0;
    for i = [1:length(y)]
        error = error + (y_pred(i) - y(i)) * (y_pred(i) - y(i));
    end
    error = error ./ length(y);
end



