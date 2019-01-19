function [] = func()

function [muHat, count_in] = estimate(n, mu, sigma)
count_in = 0;
for ind = 1:100
    x = normrnd(mu,1,1,n);
   [muHat,sigmaHat,muCI,sigmaCI] = normfit(x);
    
   if mu > muCI(1) && mu < muCI(2)
       count_in = count_in + 1;    
   end

end
end

function [] = change_size_mu(sigma, which_part)
n_start = 100;
while n_start <= 10000
    mu_start = 0.1;
    while mu_start < 0.9 
        [muHat, count_in] = estimate(n_start, mu_start, sigma);
        if which_part == 0
            disp("mu = " + mu_start + " n = " + n_start + " : count_in = " + count_in);
        end
        mu_start = mu_start + 0.1;
    end
    disp("Variance is " + sigma + ", n is " + n_start + ", estimated mu: " + muHat);
    fprintf(1, '\n');
    n_start = n_start * 10;
end
end

% Part A & B
change_size_mu(1, 0);
fprintf(1, '\n');
% Part C
variance = 0.1;
while variance <= 10
    change_size_mu(variance, 1);
    variance = variance * 10;
end
end