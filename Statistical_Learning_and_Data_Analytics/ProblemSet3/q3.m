x1 = [1; 4; 400];
x2 = [3; 5; 500];
x3 = [3; 2; 450];
x4 = [3; 1; 400];
x5 = [1; 3; 425];


x = [x1,x2,x3,x4,x5];
x_centered = zeros(size(x));
x_standardized = zeros(size(x));

% Centralize
for i = (1:3)
    x_centered(i,:) = x(i,:) - mean(x(i,:));
end

cov = x_centered * transpose(x_centered)./5;
[v1, e1] = eig(cov);

% Standardize
for i = (1:3)
    x_standardized(i,:) = x_centered(i,:) / std(x_centered(i,:));
end

cov = x_standardized * transpose(x_standardized)./5;
[v2, e2] = eig(cov);

x_standardized = transpose(x_standardized);
z1 = x_standardized * v2(:,3);
z2 = x_standardized * v2(:,2);

figure;
scatter(z1,z2, 'filled');
title("Expression of the data in 2D");
ylabel("2nd (z2) Principal Component");
xlabel("1st (z1) Principal Component");

pvm_z1 = sum(z1.^2) / 5; 
pvm_z2 = sum(z2.^2) / 5;
total_variance = sum(sum(x_standardized.*x_standardized)) / 5;
ratio = (pvm_z1+pvm_z2)/total_variance*100;

