clearvars
close all
clc

load DATA
numChannels = 8;

%% Sequences selection in relation to the Gestures

DATA_Temp = {};
for i=1:length(DATA)
    gestureCode = DATA{i, 6}';
    if sum(gestureCode == [0,2,4])
        [r, c]=size(DATA_Temp);
        DATA_Temp(r+1,:)= DATA(i, :);
    end
end

DATA = DATA_Temp;

clearvars -except numChannels DATA

%% Treatment

fs = 200; % Hz

fpass_BP_low = 50;  % Hz
fpass_BP_high = 450;  % Hz

fpass_LP = 5; % Hz

for i=1:length(DATA)
    signals = DATA{i, 5}';

    % signals_BP = bandpass(signals, [fpass_BP_low fpass_BP_high],fs);
    signals_BP = signals;

    signals_Rect = abs(signals_BP);

    signals_LP = lowpass(signals_Rect,fpass_LP,fs);

    DATA{i, 8} = signals_LP';
end

figure
tiledlayout(2,2)
time = (1:length(signals))/fs;

nexttile
stackedplot(time, signals,DisplayLabels="Channel " + (1:numChannels))
title("Signals")

nexttile
stackedplot(time, signals_BP,DisplayLabels="Channel " + (1:numChannels))
title("after Band-pass filter")

nexttile
stackedplot(time, signals_Rect,DisplayLabels="Channel " + (1:numChannels))
title("after Rectification")

nexttile
stackedplot(time, signals_LP,DisplayLabels="Channel " + (1:numChannels))
title("after Low-pass filter")


%%

k1=1;
k2=1;
k3=1;

for i=1:length(DATA)
    gestureCode = DATA{i, 6}';
    switch gestureCode
        case 0
            nSamples = length(DATA{i, 8}(1,:));
            Neutral.Ch1(1:nSamples,k1) = DATA{i, 8}(1,:);
            Neutral.Ch2(1:nSamples,k1) = DATA{i, 8}(2,:);
            Neutral.Ch3(1:nSamples,k1) = DATA{i, 8}(3,:);
            Neutral.Ch4(1:nSamples,k1) = DATA{i, 8}(4,:);
            Neutral.Ch5(1:nSamples,k1) = DATA{i, 8}(5,:);
            Neutral.Ch6(1:nSamples,k1) = DATA{i, 8}(6,:);
            Neutral.Ch7(1:nSamples,k1) = DATA{i, 8}(7,:);
            Neutral.Ch8(1:nSamples,k1) = DATA{i, 8}(8,:);
            k1=k1+1;
        case 2
            nSamples = length(DATA{i, 8}(1,:));
            Flexion.Ch1(1:nSamples,k1) = DATA{i, 8}(1,:);
            Flexion.Ch2(1:nSamples,k1) = DATA{i, 8}(2,:);
            Flexion.Ch3(1:nSamples,k1) = DATA{i, 8}(3,:);
            Flexion.Ch4(1:nSamples,k1) = DATA{i, 8}(4,:);
            Flexion.Ch5(1:nSamples,k1) = DATA{i, 8}(5,:);
            Flexion.Ch6(1:nSamples,k1) = DATA{i, 8}(6,:);
            Flexion.Ch7(1:nSamples,k1) = DATA{i, 8}(7,:);
            Flexion.Ch8(1:nSamples,k1) = DATA{i, 8}(8,:);
            k2=k2+1;
        case 4
            nSamples = length(DATA{i, 8}(1,:));
            Extension.Ch1(1:nSamples,k1) = DATA{i, 8}(1,:);
            Extension.Ch2(1:nSamples,k1) = DATA{i, 8}(2,:);
            Extension.Ch3(1:nSamples,k1) = DATA{i, 8}(3,:);
            Extension.Ch4(1:nSamples,k1) = DATA{i, 8}(4,:);
            Extension.Ch5(1:nSamples,k1) = DATA{i, 8}(5,:);
            Extension.Ch6(1:nSamples,k1) = DATA{i, 8}(6,:);
            Extension.Ch7(1:nSamples,k1) = DATA{i, 8}(7,:);
            Extension.Ch8(1:nSamples,k1) = DATA{i, 8}(8,:);
            k3=k3+1;
    end
end

figure
subplot(1,3,1)
t = table(Neutral.Ch1, Neutral.Ch2, Neutral.Ch3, Neutral.Ch4, Neutral.Ch5, ...
    Neutral.Ch6, Neutral.Ch7, Neutral.Ch8);
stackedplot(t)
subplot(1,3,2)
t = table(Flexion.Ch1, Flexion.Ch2, Flexion.Ch3, Flexion.Ch4, Flexion.Ch5, ...
    Flexion.Ch6, Flexion.Ch7, Flexion.Ch8);
stackedplot(t)
subplot(1,3,3)
t = table(Extension.Ch1, Extension.Ch2, Extension.Ch3, Extension.Ch4, Extension.Ch5, ...
    Extension.Ch6, Extension.Ch7, Extension.Ch8);
stackedplot(t)












