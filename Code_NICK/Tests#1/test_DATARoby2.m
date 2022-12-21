clearvars
close all
clc

load DATA_Roby3
DATA = DATA_Roby2;
numChannels = 8;

%% Treatment

fs = 100; % Hz

fpass_BP_low = 50;  % Hz
fpass_BP_high = 450;  % Hz

fpass_LP = 5; % Hz

for i=1:length(DATA(:,1))
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

%% Normalization
clearvars -except numChannels fs DATA

Genders = ["Female" "Male"];
maxSub = max(cell2mat(DATA(:,4)));

Peaks = zeros(maxSub+1,numChannels,2);
for i=1:length(DATA(:,1))
    iSub = DATA{i, 4}+1;
    iG = find(DATA{i, 3}==Genders);
    maxPeaks_i = max(DATA{i, 8}');
    Peaks(iSub,:,iG) = max(Peaks(iSub,:,iG), maxPeaks_i);
end

for i=1:length(DATA(:,1))
    iSub = DATA{i, 4}+1;
    iG = find(DATA{i, 3}==Genders);
    maxPeaks_i = Peaks(iSub,:,iG);
    DATA{i,9} = DATA{i,8}./maxPeaks_i';
end

%%
clearvars -except fs DATA

k1=1;
k2=1;
k3=1;

for i=1:length(DATA(:,1))
    gestureCode = DATA{i, 6}';
    switch gestureCode
        case 0
            nSamples = length(DATA{i, 9}(1,:));
            Neutral.Ch1(1:nSamples,k1) = DATA{i, 9}(1,:);
            Neutral.Ch2(1:nSamples,k1) = DATA{i, 9}(2,:);
            Neutral.Ch3(1:nSamples,k1) = DATA{i, 9}(3,:);
            Neutral.Ch4(1:nSamples,k1) = DATA{i, 9}(4,:);
            Neutral.Ch5(1:nSamples,k1) = DATA{i, 9}(5,:);
            Neutral.Ch6(1:nSamples,k1) = DATA{i, 9}(6,:);
            Neutral.Ch7(1:nSamples,k1) = DATA{i, 9}(7,:);
            Neutral.Ch8(1:nSamples,k1) = DATA{i, 9}(8,:);
            k1=k1+1;
        case 2
            nSamples = length(DATA{i, 9}(1,:));
            Flexion.Ch1(1:nSamples,k2) = DATA{i, 9}(1,:);
            Flexion.Ch2(1:nSamples,k2) = DATA{i, 9}(2,:);
            Flexion.Ch3(1:nSamples,k2) = DATA{i, 9}(3,:);
            Flexion.Ch4(1:nSamples,k2) = DATA{i, 9}(4,:);
            Flexion.Ch5(1:nSamples,k2) = DATA{i, 9}(5,:);
            Flexion.Ch6(1:nSamples,k2) = DATA{i, 9}(6,:);
            Flexion.Ch7(1:nSamples,k2) = DATA{i, 9}(7,:);
            Flexion.Ch8(1:nSamples,k2) = DATA{i, 9}(8,:);
            k2=k2+1;
        case 4
            nSamples = length(DATA{i, 9}(1,:));
            Extension.Ch1(1:nSamples,k3) = DATA{i, 9}(1,:);
            Extension.Ch2(1:nSamples,k3) = DATA{i, 9}(2,:);
            Extension.Ch3(1:nSamples,k3) = DATA{i, 9}(3,:);
            Extension.Ch4(1:nSamples,k3) = DATA{i, 9}(4,:);
            Extension.Ch5(1:nSamples,k3) = DATA{i, 9}(5,:);
            Extension.Ch6(1:nSamples,k3) = DATA{i, 9}(6,:);
            Extension.Ch7(1:nSamples,k3) = DATA{i, 9}(7,:);
            Extension.Ch8(1:nSamples,k3) = DATA{i, 9}(8,:);
            k3=k3+1;
    end
end

% figure
% subplot(1,3,1)
% t = table(Neutral.Ch1, Neutral.Ch2, Neutral.Ch3, Neutral.Ch4, Neutral.Ch5, ...
%     Neutral.Ch6, Neutral.Ch7, Neutral.Ch8);
% stackedplot(t,"LegendVisible","off",'LegendLabels',"")
% subplot(1,3,2)
% t = table(Flexion.Ch1, Flexion.Ch2, Flexion.Ch3, Flexion.Ch4, Flexion.Ch5, ...
%     Flexion.Ch6, Flexion.Ch7, Flexion.Ch8);
% stackedplot(t,"LegendVisible","off")
% subplot(1,3,3)
% t = table(Extension.Ch1, Extension.Ch2, Extension.Ch3, Extension.Ch4, Extension.Ch5, ...
%     Extension.Ch6, Extension.Ch7, Extension.Ch8);
% stackedplot(t,"LegendVisible","off")

figure
subplot(8,3,1)
plot(Neutral.Ch1)
xlim([0 500])
subplot(8,3,4)
plot(Neutral.Ch2)
xlim([0 500])
subplot(8,3,7)
plot(Neutral.Ch3)
xlim([0 500])
subplot(8,3,10)
plot(Neutral.Ch4)
xlim([0 500])
subplot(8,3,13)
plot(Neutral.Ch5)
xlim([0 500])
subplot(8,3,16)
plot(Neutral.Ch6)
xlim([0 500])
subplot(8,3,19)
plot(Neutral.Ch7)
xlim([0 500])
subplot(8,3,22)
plot(Neutral.Ch8)
xlim([0 500])
xlabel("Neutral")

subplot(8,3,2)
plot(Flexion.Ch1)
xlim([0 500])
subplot(8,3,5)
plot(Flexion.Ch2)
xlim([0 500])
subplot(8,3,8)
plot(Flexion.Ch3)
xlim([0 500])
subplot(8,3,11)
plot(Flexion.Ch4)
xlim([0 500])
subplot(8,3,14)
plot(Flexion.Ch5)
xlim([0 500])
subplot(8,3,17)
plot(Flexion.Ch6)
xlim([0 500])
subplot(8,3,20)
plot(Flexion.Ch7)
xlim([0 500])
subplot(8,3,23)
plot(Flexion.Ch8)
xlim([0 500])
xlabel("Flexion")

subplot(8,3,3)
plot(Extension.Ch1)
xlim([0 500])
subplot(8,3,6)
plot(Extension.Ch2)
xlim([0 500])
subplot(8,3,9)
plot(Extension.Ch3)
xlim([0 500])
subplot(8,3,12)
plot(Extension.Ch4)
xlim([0 500])
subplot(8,3,15)
plot(Extension.Ch5)
xlim([0 500])
subplot(8,3,18)
plot(Extension.Ch6)
xlim([0 500])
subplot(8,3,21)
plot(Extension.Ch7)
xlim([0 500])
subplot(8,3,24)
plot(Extension.Ch8)
xlim([0 500])
xlabel("Extension")

%% Stupid Analisys
clearvars -except fs DATA
close all

XTrain = DATA(:,9);
for i=1:length(DATA(:,1))
    Temp = "";
    Temp(1,1:length(DATA{i,9})) = DATA{i,7};
    YTrain{i,1} = categorical(Temp);
end

load net2

clearvars -except DATA fs net XTrain YTrain

%%
close all

indexTest = floor(1+(length(DATA)-1)*rand)

XTest = XTrain{indexTest,:};
YTest = YTrain{indexTest,:};

[YPred, scores]= classify(net,XTest);
acc = sum(YPred == YTest)./numel(YTest)

time = (1:length(YTest))/fs;
figure
plot(time, YPred,'.-')
hold on
plot(time, YTest)
hold off
xlabel("Time [s]")
ylabel("Activity")
title("Predicted Activities")
legend(["Predicted" "Test Data"])

figure
plot(time, 100*scores','.-')
xlabel("Time [s]")
ylabel("%")
title("Scores")
legend(["Neutral         "; ...
    "Wrist Flexion   "; ....
    "Wrist Extension "])

%%

for i=1:length(DATA(:,1))
    XTest = XTrain{i,:};
    YTest = YTrain{i,:};
    YPred = classify(net,XTest);
    acc(i) = sum(YPred == YTest)./numel(YTest);
end

k=1;
for i=1:3:length(DATA(:,1))
    acc_Array(k,:) = acc(i:i+2);
    k = k+1;
end

Subjects = [...
    "Roberto" ...
    "Olmo" ...
    "Daeg" ...
    "Matteo" ...
    "Raaj" ...
    "Vasco" ...
    "Maria" ...
    "Paolo" ...
    "Matilde" ...
    "Jasmine" ...
    "Anthony" ...
    "Pinar "];

X = categorical(Subjects);
X = reordercats(X, Subjects);

figure
bar(X, 100*acc_Array)
xlabel("Subjects")
ylabel("%")
title("Accuracy")
legend(["Neutral         "; ...
    "Wrist Flexion   "; ....
    "Wrist Extension "],"Location","best")







