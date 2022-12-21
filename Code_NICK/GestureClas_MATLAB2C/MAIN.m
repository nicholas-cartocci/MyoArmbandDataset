clearvars
close all
clc

load DATA_Roby

iS = 1;
Seq = DATA_Roby{iS, 5};

for i = 1:45%length(Seq)
    
    DATA = Seq(:,i);

    YPred(i) = gestureClassification_C(DATA);
end

clear gestureClassification

