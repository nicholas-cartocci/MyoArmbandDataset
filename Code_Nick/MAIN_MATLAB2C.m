clearvars
close all
clc

cfg = coder.config('mex');
cfg.DeepLearningConfig = coder.DeepLearningConfig('TargetLibrary','none');

matrixInput = coder.typeof(double(0),[8 1]);

codegen -config cfg gestureClassification_C -args {matrixInput} -report