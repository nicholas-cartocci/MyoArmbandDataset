function [Perc] = gestureClassification_C(DATA)

numChannels = 8;
sizeBUFFER = 40;

persistent net
persistent BUFFER
persistent iBUFFER

if isempty(BUFFER)
    BUFFER = zeros(numChannels, sizeBUFFER);
end
if isempty(iBUFFER)
    iBUFFER = 1;
end
if isempty(net)
    net = coder.loadDeepLearningNetwork('net_7epochs.mat');
end

if iBUFFER<sizeBUFFER+1
    BUFFER(:, iBUFFER) = DATA;
    iBUFFER = iBUFFER+1;
    [~, Perc] = classify(net, zeros(numChannels,1));
else
    Temp = BUFFER(:,2:sizeBUFFER);
    BUFFER(:,1:sizeBUFFER-1) = Temp;
    BUFFER(:,sizeBUFFER) = DATA;

    % Treatment
    fs = 100; % Hz
    fpass_LP = 5; % Hz

    signals = BUFFER';
    signals_Rect = abs(signals);
    [b,a]=butter(4,fpass_LP/(fs/2));
    signals_LP=filter(b,a,signals_Rect)';

    % Normalization
    Peaks_Roberto = [62.5341966817099,115.454332583449,114.153665342948,65.7814640082061,40.2525403778840,100.421821047113,79.0393829388866,71.4412803477133]';
    signal_N = signals_LP(:,sizeBUFFER)./Peaks_Roberto;

    % Classification
    [net, ~, Perc] = classifyAndUpdateState(net,signal_N);

end

end
