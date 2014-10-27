/** \mainpage PBToolset 
* 
* \section PBToolset PBToolset General
* \copydoc md_C:_Users_Piotr_Documents_Projekty_PBToolset_README
* \section Contents
* \subsection C_MatlabExchange 
* Narzędzie pozwalające na zgrywanie do jednego pliku szeregu danych wraz z nazwami. 
* Po wczytanie do matlaba zmienne są importowane do workspace wraz z nazwami nadanymi im podczas 
* nagrywania
* Struktura pliku:
* 1. Unsigned int - ilość wpisów
* 2. MAX_ENTRY*unsigned long - miejsce na kolejne wpisy - dane zawierające informacje o położeniu wpisu w pliku (offset)
* 
* Matlab code for reading containers: ImportDumpFile.m
* 
* Matlab code for writing array: ExportArrayToFile.m
* \subsection Geom
* Zestaw klas obsługujących podstawową geometrię. W skład biblioteki wchodzą:
* \li C_Point - obsługa punktów
* \li C_Vector - obsługa wektorów
* \li C_Line - obsługa linii
*/
