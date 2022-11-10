function Bmean = gesture_fnc(path, datafile, label)
  % Load data
  bfile = fopen([path datafile]);
  bdata = fread(bfile, 'short');
  totalSize = size(bdata);
  nRows = totalSize / 8;
  B = reshape(bdata, 8, nRows);

 plot = false;
  
  % -----------------------------------------------------------------------------

  % Plot raw data
  if plot
    figure
    for i = 1:8
      subplot(2, 4, i);
      plot(B(i, :));
    endfor
  endif

  % -----------------------------------------------------------------------------

  % Absolute
  Bs = B;
  for i = 1:8
    Bs(i, :) = abs(B(i, :));
  endfor

  if plot
    figure
    for i = 1:8
      subplot(2, 4, i);
      plot(Bs(i, :));
    endfor
  endif

  % -----------------------------------------------------------------------------

  % Filter data
  [b, a] = butter(2, 0.01);
  Bf = B;
  for i = 1:8
    Bf(i, :) = filter(b, a, Bs(i, :));
  endfor

  if plot
    figure
    for i = 1:8
      subplot(2, 4, i);
      plot(Bf(i, :));
    endfor
  endif

  % -----------------------------------------------------------------------------

  % Calculate mean
  for i = 1:8
    Bmean(i) = mean(Bs(i, :));
  endfor

  % Do Threshold
  threshold = 10.0;
  for i = 1:8
    if Bmean(i) > threshold
      Bth(i) = 1;
    else
      Bth(i) = 0;
    endif
  endfor
  
  printf('Dataset %s, gesture: %s\n', datafile, label);
  for i = 1:8
    printf(' EMG %d: %f (%d)\n', i, Bmean(i), Bth(i));
  endfor
endfunction