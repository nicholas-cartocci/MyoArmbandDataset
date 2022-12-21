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

iClasLabels = 1+[0,2,4,5];
Labels = categorical(labels(iClasLabels));

Genders = ["Female" "Male"];
dataScope1 = ["PreTrainingDataset" "EvaluationDataset"];
dataScope2 = ["\training0" "\Test0" "\Test1"];

MaxSub = 15;
nChannels = 8;

k=1;

for idataScope1 = 1:length(dataScope1)
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

                    if ~isempty(Labels((labels(iLabel)==Labels)))
                    DATA{k,1} = dataScope1(idataScope1);
                    DATA{k,2} = dataScope2(idataScope2);

                    DATA{k,3} = Gender;
                    DATA{k,4} = iSub;
                    DATA{k,5} = data;

                    DATA{k,6} = iLabel-1;
                    DATA{k,7} = Labels((labels(iLabel)==Labels));

                    fclose('all');
                    k = k+1;
                          end
                end
            end
        end
    end
end

%% Sequences selection in relation to the Gestures
clearvars -except DATA

DATA_Temp = {};
for i=1:length(DATA)
    gestureCode = DATA{i, 6}';
        [r, ~]=size(DATA_Temp);
        DATA_Temp(r+1,:)= DATA(i, :);

        % Downsampling from 200Hz to 100Hz
        DATA_Temp{r+1, 5} = downsample(DATA_Temp{r+1, 5}',2)';

        lenSeq = length(DATA_Temp{r+1, 5});
        DATA_Temp{r+1,6} = (DATA_Temp{r+1,6})*ones(1,lenSeq);
        DATA_Temp{r+1,7}(1:lenSeq) = DATA_Temp{r+1,7};
end

DATA = DATA_Temp;

%% Data Augmentation
clearvars -except DATA

Genders = ["Female" "Male"];
MaxSub = 15;

DATA_Temp = {};
for iG = Genders
    for iSub = 0:MaxSub
        tempSamples = find(cellstr(DATA(:,3))==iG & cell2mat(DATA(:,4))==iSub);
        for i = 1:length(tempSamples)-1
            for j = i+1:length(tempSamples)
                [r, ~]=size(DATA_Temp);
                DATA_Temp(r+1,3:4) = DATA(tempSamples(i),3:4);
                DATA_Temp{r+1,5} = [DATA{tempSamples(i),5} DATA{tempSamples(j),5}];
                DATA_Temp{r+1,6} = [DATA{tempSamples(i),6} DATA{tempSamples(j),6}];
                DATA_Temp{r+1,7} = [DATA{tempSamples(i),7} DATA{tempSamples(j),7}];
            end
        end
    end
end

DATA = [DATA; DATA_Temp];





















