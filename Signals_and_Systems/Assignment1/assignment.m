% recObj = audiorecorder(16000, 8, 1);
% disp('Start recording.');
% recordblocking(recObj, 7);
% disp('End of Recording.');
% 
% play(recObj);
% 
% soundArray = getaudiodata(recObj);

%     figure;
% plot(soundArray)
% title('Sound array');
% xlabel('t');
% ylabel('x(t)');
%load("sound.mat");

[soundArray,fs] = audioread('21501569_MA1_SOUND.wav');


% Crop the beginning and ending silence
partOfSoundArray = crop(soundArray);

partOfSoundArray = partOfSoundArray(5700:15000);
%     figure;
% plot(partOfSoundArray);
% title('Part of sound array');
% xlabel('t');
% ylabel('x(t)');


% Note played: A4
fund_freq = 440;
fund_per = 1 / fund_freq;
period =  floor(16000 / fund_freq);
singlePeriod = partOfSoundArray(1*period:2*period);
%     figure;
% plot(singlePeriod);
% title('Single Period');
% xlabel('t');
% ylabel('x(t)');


N = 20;
coef = zeros(1,2*N+1);
t = transpose(0:1/16000:(period)/16000);

for k = (-N:N)
    complexExp = exp(-1i * 2 * pi * (1 / fund_per) * k .* t);
    coef(k+N+1) = fund_freq.*trapz(t,singlePeriod.*complexExp);
end

coef_abs = abs(coef);
%     figure;
% plot(-N:N,coef_abs);
% title('Fourier Series Coeffients');
% xlabel('a_k');
% ylabel('Magnitude');

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%% 4,5 %%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

synthesized = zeros(1,period);

for ind = (1:period)
    sum_t = 0;
    for k = (-N:N)
       sum_t = sum_t + coef(k+N+1) * exp(1i * 2 * pi * (1 / fund_per) * k * t(ind));
    end
    synthesized(ind) = real(sum_t);
end

synthSoundArray= 1:size(partOfSoundArray);
synthSoundArray = synthesized(mod(synthSoundArray,period)+1);
%     figure;
% plot(synthSoundArray(1:4000));
% hold;
% plot(partOfSoundArray(1:4000));
% title('Synthesized Signal vs Original Signal');
% xlabel('t');
% ylabel('x(t)');
% legend('synthesized','original')
% 
audiowrite('synthesized.wav',synthSoundArray,16000);
% audiowrite('original.wav',partOfSoundArray,16000);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%% 6 %%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

N1 = 1;
for N_i = (3:20) 
    N_new =  ceil((N_i - N1) / 2.0);
    interval = -N_new : N_new;
    coef_interval = N - N_new+1 : N+1+N_new;
    coef_i = coef(coef_interval);
    synthesized = zeros(1,period);
    for ind = (1:period)
        sum_t = 0;
        for k = interval
           sum_t = sum_t + coef_i(k+N_new+1) * exp(1i * 2 * pi * (1 / fund_per) * k * t(ind));
        end
        synthesized(ind) = real(sum_t);
    end

    synthSoundArray= 1:size(partOfSoundArray);
    synthSoundArray = synthesized(mod(synthSoundArray,period)+1);
    
%     figure;
%     plot(synthSoundArray(1:4000));
%     hold;
%     plot(partOfSoundArray(1:4000));
%     title('Synthesized Signal vs Original Signal');
%     xlabel('t');
%     ylabel('x(t)');
%     legend('synthesized','original')
%     
%     name = 'sythesized';
%     name = strcat(name, num2str(N2));
%     name = strcat(name, '.wav');
%     audiowrite(name,synthSoundArray,16000);

end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%% 7 %%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
coef_fix_mag = zeros(1,length(coef));
for i = (1:length(coef))
    coef_fix_mag(i) = coef(i) / abs(coef(i));
end
synthesized_fix_mag = zeros(1,period);

for ind = (1:period)
    sum_t = 0;
    for k = (-N:N)
       sum_t = sum_t + coef_fix_mag(k+N+1) * exp(1i * 2 * pi * (1 / fund_per) * k * t(ind));
    end
    synthesized_fix_mag(ind) = real(sum_t);
end

synthSoundArray_fix_mag= 1:size(partOfSoundArray);
synthSoundArray_fix_mag = synthesized_fix_mag(mod(synthSoundArray_fix_mag,period)+1);
% figure;
% plot(synthSoundArray_fix_mag(1:4000));
% hold;
% plot(partOfSoundArray(1:4000));
% title('Synthesized Signal(fix magnitude coefficients)vs Original Signal');
% xlabel('t');
% ylabel('x(t)');
% legend('synthesized','original')
% audiowrite('fix_mag.wav',synthSoundArray_fix_mag,16000);


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%% 8 %%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
coef_fix_phase = zeros(1,length(coef));
for i = (1:length(coef))
    coef_fix_phase(i) = abs(real(coef(i)));
end

synthesized_fix_phase = zeros(1,period);

for ind = (1:period)
    sum_t = 0;
    for k = (-N:N)
       sum_t = sum_t + coef_fix_phase(k+N+1) * exp(1i * 2 * pi * (1 / fund_per) * k * t(ind));
    end
    synthesized_fix_phase(ind) = real(sum_t);
end

% synthSoundArray_fix_phase= 1:size(partOfSoundArray);
% synthSoundArray_fix_phase = synthesized_fix_phase(mod(synthSoundArray_fix_phase,period)+1);
% figure;
% plot(synthSoundArray_fix_phase(1:4000));
% hold;
% plot(partOfSoundArray(1:4000));
% title('Synthesized Signal(fix phase coefficients)vs Original Signal');
% xlabel('t');
% ylabel('x(t)');
% legend('synthesized','original')
% audiowrite('fix_phase.wav',synthSoundArray_fix_phase,16000);



function partOfSoundArray = crop(soundArray)
    
    % Crop the sound array
    startingInd = 0;
    endingInd = 0;
    for i = (20000:length(soundArray))
        if (startingInd == 0 && abs(soundArray(i)) > 0.01)
            startingInd = i;
        end
        if (endingInd == 0 && abs(soundArray(length(soundArray)-i)) > 0.01)
            endingInd = length(soundArray)-i;
        end
    end
    partOfSoundArray = soundArray(startingInd:endingInd);
end