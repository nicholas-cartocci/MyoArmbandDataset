clearvars
close all
clc

path = 'C:\Users\ncartocci\Documents\GitHub\MyoArmbandDataset\PreTrainingDataset\Female0\training0';
datafile = '\classe_7.dat';
label = 'ciao';

Bmean = gesture_fnc2(path, datafile, label)