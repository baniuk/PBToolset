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
		filedata.write((char*)&datatowrite,sizeof(unsigned long)); // przesówanie wskaŸnika plików
}

C_DumpAll::~C_DumpAll(void)
{
	filedata.seekp(ios::beg);		// begining of the file
	filedata.write((char*)&lastpozindex, sizeof(unsigned int));	// number of entries
	for(unsigned int a=0; a<lastpozindex; ++a)
		filedata.write((char*)&offset[a], sizeof(unsigned long));	// write table of offsets
	filedata.close();
}