function ExportArrayToFile(filename,data)
% Eksportuje tablicê 2D lub 1D data do pliku binarnego
% Plik binarny jest odczytywany przez C_MatlabExchange::ReadData
% data jest konwertowane do tablicy 1D rzedami

rdata = double(reshape(data',1,[]));
[rows,cols] = size(data);
fid = fopen(filename,'w');
fwrite(fid, rows, 'uint32');
fwrite(fid, cols, 'uint32');
fwrite(fid, rdata, 'double', 0, 'l');
fclose(fid);
