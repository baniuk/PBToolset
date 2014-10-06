/**
* \file C_DumpAll.cpp
* \brief Class definition file for C_Dump class
* \author PB
* \date 2014/09/25
*/

#include "DumpAll/C_DumpAll.hpp"

/**
* \brief Main constructor
* \details Construct dump object associated with certain file
* \param[in] filename name of the data file to be created
* \exception ios_base::badbit - on disk read error etc
* \exception ios_base::failbit - wrong conversion etc
* \see C++ Programing language pp. 1080
*/
C_DumpAll::C_DumpAll(const char* filename)
{
	// setting error handling to throwing exceptions on these situations
	unsigned long datatowrite = 0;
	filedata.exceptions(filedata.exceptions() | ios_base::badbit | ios_base::failbit);
	filedata.open(filename,ios_base::binary);
	lastpozindex = 0;
	filedata.write((char*)&datatowrite,sizeof(unsigned int));	// miejsce na ilosc wpisów
	for(std::size_t a=0; a<MAX_ENTRY; ++a)
		filedata.write((char*)&datatowrite,sizeof(unsigned long)); // przesówanie wskaźnika plików
}

C_DumpAll::~C_DumpAll(void)
{
	filedata.seekp(ios::beg);		// begining of the file
	filedata.write((char*)&lastpozindex, sizeof(unsigned int));	// number of entries
	for(unsigned int a=0; a<lastpozindex; ++a)
		filedata.write((char*)&offset[a], sizeof(unsigned long));	// write table of offsets
	filedata.close();
}

/**
* \brief konwertuje łańcuch z typem zmennej na typ numeryczny
* \details Oeracja wymagana aby obsłużyć template metody \c AddEntry tak aby mogła ona zapisać kod typu danych w kontenerze
* w sposób możliwy do odczytania przez Matlaba
* \param[in] _type typ zmiennej zwrócony przez typeid (łańcuch)
* \code{cpp}
* type = decodeType(typeid(data).name());
* \endcode
* \return kod typu danych
* \retval dataType
* \exception std::logic_error - when MAX_ENTRY reached or unsuppoerted type of data
* \see dataType
*/
dataType C_DumpAll::decodeType(std::string _type)
{
	dataType type = dataType::UNSUPPORTED;  // type of data to write
	std::string name_of_type(_type);	// copy name of T to string.
	// mapping known types
	if(name_of_type.find("float")!=string::npos)	// it is float
		type = dataType::FLOAT;
	if(name_of_type.find("double")!=string::npos)	// it is double
		type = dataType::DOUBLE;
	if(name_of_type.find("unsigned short")!=string::npos)
		type = dataType::USHORT;
	if(type==dataType::UNSUPPORTED)
		throw std::logic_error("Unknown Type " + name_of_type);
	if(lastpozindex >= MAX_ENTRY)
		throw std::logic_error("Maximal entry number reached");
	return type;
}