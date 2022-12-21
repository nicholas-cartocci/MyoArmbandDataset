function Bmean = gesture_fnc2(path, datafile, label)
% Load data
bfile = fopen([path datafile]);
bdata = fread(bfile, 'short');
totalSize = length(bdata);
nRows = totalSize / 8;
B = reshape(bdata, 8, nRows);

plotF1 = false;
plotF2 = false;
plotF3 = true;

% -----------------------------------------------------------------------------

% Plot raw data
if plotF1
    figure
    for i = 1:8
        subplot(2, 4, i);
        plot(B(i, :));
    end
end

% -----------------------------------------------------------------------------

% Absolute
Bs = B;
for i = 1:8
    Bs(i, :) = abs(B(i, :));
end

if plotF2
    figure
    for i = 1:8
        subplot(2, 4, i);
        plot(Bs(i, :));
    end
end

% -----------------------------------------------------------------------------

% Filter data
[b, a] = butter(2, 0.01);
Bf = B;
for i = 1:8
    Bf(i, :) = filter(b, a, Bs(i, :));
end

if plotF3
    figure
    for i = 1:8
        subplot(2, 4, i);
        plot(Bf(i, :));
    end
end

% -----------------------------------------------------------------------------

% Calculate mean
for i = 1:8
    Bmean(i) = mean(Bs(i, :));
end

% Do Threshold
threshold = 10.0;
for i = 1:8
    if Bmean(i) > threshold
        Bth(i) = 1;
    else
        Bth(i) = 0;
    end
end

fprintf('Dataset %s, gesture: %s\n', datafile, label);
for i = 1:8
    fprintf(' EMG %d: %f (%d)\n', i, Bmean(i), Bth(i));
end
end