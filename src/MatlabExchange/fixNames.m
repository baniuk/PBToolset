function str_mod = fixNames(str_in)
%Fixes names of the variables crearted basing on filename
% - -> _
% . -> _

% .
str_in(find(str_in=='.')) = '_';

% -
str_in(find(str_in=='-')) = '_';

str_mod = str_in;

end

