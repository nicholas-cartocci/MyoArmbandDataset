clearvars
close all
clc

labels = [ ...
    "Neutral         "; ...
    "Wrist Flexion   "; ....
    "Wrist Extension "];

Gender = "Male";

path = "C:\Users\ncartocci\Documents\GitHub\MyoArmbandDataset\Code_Nick\Roberto_data";

Table_n = readtable(path + "\dm_log_2022-11-07_neutral.dat.csv");
DATA_n = table2array(Table_n(:,2:9))';
DATA_Roby{1,3} = Gender;
DATA_Roby{1,4} = 16;
DATA_Roby{1,5} = DATA_n;
DATA_Roby{1,6} = 0;
DATA_Roby{1,7} = labels(1);


Table_f = readtable(path + "\dm_log_2022-11-07_flexion.dat.csv");
DATA_f = table2array(Table_f(:,2:9))';
DATA_Roby{2,3} = Gender;
DATA_Roby{2,4} = 16;
DATA_Roby{2,5} = DATA_f;
DATA_Roby{2,6} = 2;
DATA_Roby{2,7} = labels(2);

Table_e = readtable(path + "\dm_log_2022-11-07_extension.dat.csv");
DATA_e = table2array(Table_e(:,2:9))';
DATA_Roby{3,3} = Gender;
DATA_Roby{3,4} = 16;
DATA_Roby{3,5} = DATA_e;
DATA_Roby{3,6} = 4;
DATA_Roby{3,7} = labels(3);

