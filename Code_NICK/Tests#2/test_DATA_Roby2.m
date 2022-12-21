clearvars
close all
clc

load DATA_Roby
numChannels = 8;

DATA = DATA_Roby;

%% Treatment

fs = 100; % Hz

fpass_BP_low = 50;  % Hz
fpass_BP_high = 450;  % Hz

fpass_LP = 5; % Hz

for i=1:length(DATA)
    floor(100*i/length(DATA))
    clc

    signals = DATA{i, 5}';

    % signals_BP = bandpass(signals, [fpass_BP_low fpass_BP_high],fs);
    signals_BP = signals;

    signals_Rect = abs(signals_BP);

    signals_LP = lowpass(signals_Rect,fpass_LP,fs);

    DATA{i, 8} = signals_LP';
end

%% Normalization
clearvars -except numChannels fs DATA

Genders = ["Female" "Male"];
maxSub = max(cell2mat(DATA(:,4)));

Peaks = zeros(maxSub+1,numChannels,2);
for i=1:length(DATA)
    iSub = DATA{i, 4}+1;
    iG = find(DATA{i, 3}==Genders);
    maxPeaks_i = max(DATA{i, 8}');
    Peaks(iSub,:,iG) = max(Peaks(iSub,:,iG), maxPeaks_i);
end

for i=1:length(DATA)
    iSub = DATA{i, 4}+1;
    iG = find(DATA{i, 3}==Genders);
    maxPeaks_i = Peaks(iSub,:,iG);
    DATA{i,9} = DATA{i,8}./maxPeaks_i';
end

%% Stupid Analisys
clearvars -except fs DATA
close all

XTrain = DATA(:,9);
for i=1:length(DATA(:,1))
    Temp = "";
    Temp(1,1:length(DATA{i,9})) = DATA{i,7};
    YTrain{i,1} = categorical(Temp);
end

load net_7epochs

clearvars -except fs DATA net XTrain YTrain

%%
close all

indexTest = 62%floor(1+(length(DATA)-1)*rand)

XTest = XTrain{indexTest,:};
YTest = YTrain{indexTest,:};

[YPred, scores]= classify(net,XTest);
acc = sum(YPred == YTest)./numel(YTest)

resetState(net);
for i=1:length(XTest)
[net,YPred2(i), scores2] = classifyAndUpdateState(net,XTest(:,i));
end
acc2 = sum(YPred2 == YTest)./numel(YTest)


time = (1:length(YTest))/fs;
figure
plot(time, YPred,'.-')
hold on
plot(time, YPred2,'.-')
plot(time, YTest)
hold off
xlabel("Time [s]")
ylabel("Activity")
title("Predicted Activities")
legend(["Predicted" "Predicted2" "Test Data"])





