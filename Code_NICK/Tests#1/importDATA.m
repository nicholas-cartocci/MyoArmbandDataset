clearvars
close all
clc

labels = [ ...
    "Neutral         "; ...
    "Radial Deviation"; ...
    "Wrist Flexion   "; ...
    "Ulnar Deviation "; ...
    "Wrist Extension "; ...
    "Hand Close      "; ...
    "Hand Open       "];

Genders = ["Female" "Male"];
dataScope1 = ["PreTrainingDataset" "EvaluationDataset"];
dataScope2 = ["\training0" "\Test0" "\Test1"];

MaxSub = 15;
nChannels = 8;

k=1;

for idataScope1 = 1: length(dataScope1)
    path = "C:\Users\ncartocci\Documents\GitHub\MyoArmbandDataset\" + dataScope1(idataScope1);


    for idataScope2 = 1: length(dataScope2)

        for iGender = 1:length(Genders)
            Gender = Genders(iGender);

            for iSub = 0:MaxSub
                Folder = Gender+num2str(iSub);
                url = convertStringsToChars(path + '\' + Folder + dataScope2(idataScope2));
                numSeq= length(dir([url '/*.dat']));

                for iClasse = 0:numSeq-1
                    url2 = url + "\classe_" + num2str(iClasse) + ".dat";

                    % Load data
                    bfile = fopen(url2);
                    bdata = fread(bfile, 'short');
                    totalSize = length(bdata);
                    nRows = totalSize / nChannels ;
                    data = reshape(bdata, nChannels, nRows);
                    iLabel = 1+mod(iClasse,7);

                    DATA{k,1} = dataScope1(idataScope1);
                    DATA{k,2} = dataScope2(idataScope2);

                    DATA{k,3} = Gender;
                    DATA{k,4} = iSub;
                    DATA{k,5} = data;
                    DATA{k,6} = iLabel-1;
                    DATA{k,7} = labels(iLabel);

                    fclose('all');
                    k = k+1;
                end
            end
        end
    end
end
