clearvars
close all
clc

load DATA_Roby

DATA_Roberto = DATA(1:6,:);

% Raw DATA
DATA_Neutral_Raw = DATA_Roberto{1, 5};
DATA_Flexion_Raw = DATA_Roberto{2, 5};  
DATA_Extension_Raw = DATA_Roberto{3, 5};  

DATA_Dynamic_Raw = DATA_Roberto{4, 5};  
DATA_MVCFlex_Raw = DATA_Roberto{5, 5};
DATA_MVCExt_Raw = DATA_Roberto{6, 5};  

% Processed DATA
DATA_Neutral_Proc = DATA_Roberto{1, 9};
DATA_Flexion_Proc = DATA_Roberto{2, 9};  
DATA_Extension_Proc = DATA_Roberto{3, 9};  

DATA_Dynamic_Proc = DATA_Roberto{4, 9};  
DATA_MVCFlex_Proc = DATA_Roberto{5, 9};
DATA_MVCExt_Proc = DATA_Roberto{6, 9};  

%% Save the variables

save('DATA_Neutral_Raw','DATA_Neutral_Raw')
save('DATA_Flexion_Raw','DATA_Flexion_Raw')
save('DATA_Extension_Raw','DATA_Extension_Raw')

save('DATA_Dynamic_Raw','DATA_Dynamic_Raw')
save('DATA_MVCFlex_Raw','DATA_MVCFlex_Raw')
save('DATA_MVCExt_Raw','DATA_MVCExt_Raw')

save('DATA_Neutral_Proc','DATA_Neutral_Proc')
save('DATA_Flexion_Proc','DATA_Flexion_Proc')
save('DATA_Extension_Proc','DATA_Extension_Proc')

save('DATA_Dynamic_Proc','DATA_Dynamic_Proc')
save('DATA_MVCFlex_Proc','DATA_MVCFlex_Proc')
save('DATA_MVCExt_Proc','DATA_MVCExt_Proc')








