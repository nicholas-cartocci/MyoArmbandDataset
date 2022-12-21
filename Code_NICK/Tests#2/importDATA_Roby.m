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
        DATA_Roby{k,2} = Subjects(i+1);
        DATA_Roby{k,3} = Genders(i+1);
        DATA_Roby{k,4} = i;
        DATA_Roby{k,5} = DATA_n;

        lenSeq = length(DATA_n);

        if contains(list_files(j,1).name, "neutral")
            DATA_Roby{k,6} = 0*ones(1,lenSeq);
            DATA_Roby{k,7}(1:lenSeq) = labels(1);
        elseif contains(list_files(j,1).name, "flexion")
            DATA_Roby{k,6} = 2*ones(1,lenSeq);
            DATA_Roby{k,7}(1:lenSeq) = labels(2);
        elseif contains(list_files(j,1).name, "extension")
            DATA_Roby{k,6} = 4*ones(1,lenSeq);
            DATA_Roby{k,7}(1:lenSeq) = labels(3);
        elseif contains(list_files(j,1).name, "dynamic")
            ls5 = round(lenSeq/5);

            DATA_Roby{k,6}(1:ls5) = 0;
            DATA_Roby{k,6}(ls5+1:2*ls5) = 2;
            DATA_Roby{k,6}(2*ls5+1:3*ls5) = 0;
            DATA_Roby{k,6}(3*ls5+1:4*ls5) = 4;
            DATA_Roby{k,6}(4*ls5+1:lenSeq) = 0;

            DATA_Roby{k,7}(1:ls5) = labels(1);
            DATA_Roby{k,7}(ls5+1:2*ls5) = labels(2);
            DATA_Roby{k,7}(2*ls5+1:3*ls5) = labels(1);
            DATA_Roby{k,7}(3*ls5+1:4*ls5) = labels(3);
            DATA_Roby{k,7}(4*ls5+1:lenSeq) = labels(1);
        elseif contains(list_files(j,1).name, "mvcflex")
            ls3 = round(lenSeq/3);

            DATA_Roby{k,6}(1:ls5) = 0;
            DATA_Roby{k,6}(ls5+1:2*ls5) = 2;
            DATA_Roby{k,6}(2*ls5+1:lenSeq) = 0;

            DATA_Roby{k,7}(1:ls5) = labels(1);
            DATA_Roby{k,7}(ls5+1:2*ls5) = labels(2);
            DATA_Roby{k,7}(2*ls5+1:lenSeq) = labels(1);
        elseif contains(list_files(j,1).name, "mvcext")
            ls3 = round(lenSeq/3);

            DATA_Roby{k,6}(1:ls5) = 0;
            DATA_Roby{k,6}(ls5+1:2*ls5) = 4;
            DATA_Roby{k,6}(2*ls5+1:lenSeq) = 0;

            DATA_Roby{k,7}(1:ls5) = labels(1);
            DATA_Roby{k,7}(ls5+1:2*ls5) = labels(3);
            DATA_Roby{k,7}(2*ls5+1:lenSeq) = labels(1);
        else
            list_files(j,1).name
            k=k-1;
        end
        k=k+1;
    end
end












