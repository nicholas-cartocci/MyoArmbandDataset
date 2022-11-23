clearvars
close all
clc

cfg = coder.config( "lib", "ecoder", true );
cfg.DeepLearningConfig = coder.DeepLearningConfig('none');
cfg.TargetLang = "C++";
% cfg.FilePartitionMethod = "SingleFile";
cfg.HardwareImplementation.ProdHWDeviceType = "ARM Compatible->ARM Cortex-A";
% cfg.Toolchain = "Linaro AArch32 Linux v6.3.1";
% cfg.GenerateExampleMain = "GenerateCodeAndCompile";

matrixInput = coder.typeof(double(0),[8 1]);

codegen -config cfg gestureClassification_C -args {matrixInput} -report