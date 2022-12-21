clearvars
close all
clc

cfg = coder.config( "lib", "ecoder", true );
cfg.DeepLearningConfig = coder.DeepLearningConfig('none');
cfg.TargetLang = "C++";
cfg.GenCodeOnly = true;
cfg.HardwareImplementation.ProdHWDeviceType = "ARM Compatible->ARM Cortex-A";

codegen -config cfg get_data_Roberto -args {} -report