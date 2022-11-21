function [YPred] = gestureClassification(DATA)

numChannels = 8;
sizeBUFFER = 40;

persistent BUFFER
numel(BUFFER)

if numel(BUFFER)<numChannels*sizeBUFFER
    BUFFER = [BUFFER DATA];
    YPred = "";
else
    BUFFER = [BUFFER(:,1:end-1) DATA];

    % Treatment
    fs = 100; % Hz
    fpass_LP = 5; % Hz

    signals = BUFFER';
    signals_Rect = abs(signals);
    signals_LP = lowpass(signals_Rect,fpass_LP,fs)';

    % Normalization
    Peaks_Roberto = [62.5341966817099,115.454332583449,114.153665342948,65.7814640082061,40.2525403778840,100.421821047113,79.0393829388866,71.4412803477133]';
    signals_NORM = signals_LP./Peaks_Roberto;

    % Stupid Analisys
    load net_7epochs
    [net,YPred] = classifyAndUpdateState(net,signals_NORM(:,end));
end

end