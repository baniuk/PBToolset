function data = ImportArrayfromFile(filename)
% loads matrix saved by ExportArrayToFile

fid = fopen(filename, 'r');
a = fread(fid,1,'uint32');
b = fread(fid,1,'uint32');
data = fread(fid,[b a], 'double');
data = data';
fclose(fid);