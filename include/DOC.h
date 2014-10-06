/** \mainpage PBToolset 
* 
* \section C_MatlabExchange 
* Narzędzie pozwalające na zgrywanie do jednego pliku szeregu danych wraz z nazwami. 
* Po wczytanie do matlaba zmienne są importowane do workspace wraz z nazwami nadanymi im podczas 
* nagrywania
* Struktura pliku:
* 1. Unsigned int - ilość wpisów
* 2. MAX_ENTRY*unsigned long - miejsce na kolejne wpisy - dane zawierające informacje o położeniu wpisu w pliku (offset)
* 
* Matlab code for reading containers: ImportDumpFile.m
*/
