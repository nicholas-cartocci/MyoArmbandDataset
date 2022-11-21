clearvars
close all
clc

load DATA
numChannels = 8;

%% Treatment

Flag = 0;

if Flag
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

    % figure
    % tiledlayout(2,2)
    % time = (1:length(signals))/fs;
    %
    % nexttile
    % stackedplot(time, signals,DisplayLabels="Channel " + (1:numChannels))
    % title("Signals")
    %
    % nexttile
    % stackedplot(time, signals_BP,DisplayLabels="Channel " + (1:numChannels))
    % title("after Band-pass filter")
    %
    % nexttile
    % stackedplot(time, signals_Rect,DisplayLabels="Channel " + (1:numChannels))
    % title("after Rectification")
    %
    % nexttile
    % stackedplot(time, signals_LP,DisplayLabels="Channel " + (1:numChannels))
    % title("after Low-pass filter")
end

%% Normalization
clearvars -except numChannels DATA

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
clearvars -except DATA
close all

numSeq = length(DATA);

% Shaffling data
rng(0)
randInd = randperm(numSeq);
DATA = DATA(randInd,:);

% Data splitting in Training and Validation
idxTrain = 1:floor(0.9*numSeq);
idxVal = floor(0.9*numSeq)+1:numSeq;
dataTrain = DATA(idxTrain,:);
dataVal = DATA(idxVal,:);

XTrain = dataTrain(:,9);
for i=1:length(dataTrain)
    YTrain{i,1} = categorical(dataTrain{i,7});
end

XVal = dataVal(:,9);
for i=1:length(dataVal)
    YVal{i,1} = categorical(dataVal{i,7});
end

Flag = 0;
if Flag

    numFeatures = 8;
    numHiddenUnits = 2^7;
    numClasses = 3;

    layers = [ ...
        sequenceInputLayer(numFeatures)
        fullyConnectedLayer(numFeatures^2)
        reluLayer
        bilstmLayer(numHiddenUnits,'OutputMode','sequence')
        fullyConnectedLayer(numClasses)
        softmaxLayer
        classificationLayer];

    numEpochs = 2^7;
    miniBatchSize = 176;

    options = trainingOptions("adam", ...
        MaxEpochs=numEpochs, ...
        MiniBatchSize=miniBatchSize, ...
        Shuffle="every-epoch", ...
        Plots="training-progress", ...
        Verbose=0, ...
        ...
        ValidationData={XVal,YVal},...
        ValidationFrequency=floor(numel(XTrain)/miniBatchSize),...
        OutputNetwork='best-validation-loss');

    net = trainNetwork(XTrain,YTrain,layers,options);

else

%     load net
load net_7epochs

end

clearvars -except DATA net XTrain YTrain XVal YVal

%%
close all

indexTest = floor(1+(length(YVal)-1)*rand)

XTest = XVal{indexTest,:};
YTest = YVal{indexTest,:};

[YPred, scores]= classify(net,XTest);
acc = sum(YPred == YTest)./numel(YTest)

figure
plot(YPred,'.-')
hold on
plot(YTest)
hold off
xlabel("Time Step")
ylabel("Activity")
title("Predicted Activities")
legend(["Predicted" "Test Data"])

figure
plot(100*scores','.-')
xlabel("Time Step")
ylabel("%")
title("Scores")
legend(["Neutral         "; ...
    "Wrist Flexion   "; ....
    "Wrist Extension "])

%%

for i=1:length(YVal)
    XTest = XVal{i,:};
    YTest = YVal{i,:};
    YPred = classify(net,XTest);
    acc(i) = sum(YPred == YTest)./numel(YTest);
end

figure
plot(acc)








