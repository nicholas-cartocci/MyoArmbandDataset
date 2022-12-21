function [DATA_Neutral_Raw, DATA_Flexion_Raw, DATA_Extension_Raw, ...
    DATA_Dynamic_Raw, DATA_MVCFlex_Raw, DATA_MVCExt_Raw, ...
    DATA_Neutral_Proc, DATA_Flexion_Proc, DATA_Extension_Proc, ...
    DATA_Dynamic_Proc, DATA_MVCFlex_Proc, DATA_MVCExt_Proc] = get_data_Roberto()

% Raw DATA
DATA_Neutral_Raw = coder.load('DATA_Neutral_Raw');
DATA_Flexion_Raw = coder.load('DATA_Flexion_Raw');
DATA_Extension_Raw = coder.load('DATA_Extension_Raw');

DATA_Dynamic_Raw = coder.load('DATA_Dynamic_Raw');
DATA_MVCFlex_Raw = coder.load('DATA_MVCFlex_Raw');
DATA_MVCExt_Raw = coder.load('DATA_MVCExt_Raw');

% Processed DATA
DATA_Neutral_Proc = coder.load('DATA_Neutral_Proc');
DATA_Flexion_Proc = coder.load('DATA_Flexion_Proc');
DATA_Extension_Proc = coder.load('DATA_Extension_Proc');

DATA_Dynamic_Proc = coder.load('DATA_Dynamic_Proc');
DATA_MVCFlex_Proc = coder.load('DATA_MVCFlex_Proc');
DATA_MVCExt_Proc = coder.load('DATA_MVCExt_Proc');

end
