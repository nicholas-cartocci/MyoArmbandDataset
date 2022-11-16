clearvars
close all
clc

labels = [ ...
    "Neutral         "; ...
    "Wrist Flexion   "; ....
    "Wrist Extension "];

Subjects = [...
    "Roberto" ...
    "Olmo" ...
    "Daeg" ...
    "Matteo" ...
    "Raaj" ...
    "Vasco" ...
    "Maria" ...
    "Paolo" ...
    "Matilde" ...
    "Jasmine" ...
    "Anthony" ...
    "Pinar "];

Genders = [...
    "Male" ...
    "Male" ...
    "Male" ...
    "Male" ...
    "Male" ...
    "Male" ...
    "Female" ...
    "Male" ...
    "Female" ...
    "Female" ...
    "Male" ...
    "Female"];

MaxSub = 12;
nChannels = 8;

path = "20221116_MyoDataRecorded_Pitzalis";

k = 1;
for i=0:MaxSub-1
    url = "/20221116_Participant_P";
    path2 = path + url + num2str(i);

    list_files = dir (path2);

    for j=3:8
        path3 = path2 + "/" + list_files(j,1).name;
        Table_n = readtable(path3);

        DATA_n = table2array(Table_n(:,2:9))';
        DATA_Roby2{k,2} = Subjects(i+1);
        DATA_Roby2{k,3} = Genders(i+1);
        DATA_Roby2{k,4} = i;
        DATA_Roby2{k,5} = DATA_n;

        if contains(list_files(j,1).name, "neutral")
            DATA_Roby2{k,6} = 0;
            DATA_Roby2{k,7} = labels(1);
        elseif contains(list_files(j,1).name, "flexion")
            DATA_Roby2{k,6} = 2;
            DATA_Roby2{k,7} = labels(2);
        elseif contains(list_files(j,1).name, "extension")
            DATA_Roby2{k,6} = 4;
            DATA_Roby2{k,7} = labels(3);
        elseif contains(list_files(j,1).name, "dynamic")
            pause
        elseif contains(list_files(j,1).name, "mvcflex")
            pause
        elseif contains(list_files(j,1).name, "mvcext")
            pause
        else
            list_files(j,1).name
            k=k-1;
        end
        k=k+1;
    end
end












