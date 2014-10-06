/**
* \file C_DumpAll.hpp
* \brief Header file for C_Dump class
* \author PB
* \date 2014/09/25
*/

#ifndef C_DumpAll_h__
#define C_DumpAll_h__

#include <string>
#include <cstring>
#include <fstream>
#include <exception>
#include <typeinfo>
using namespace std;

#define MAX_ENTRY 256 ///< Maximal number of entries in file

/**
* \class dataType
* \brief Defines correct types of handled data
* \details Defines two types of data handled by library: \c double and \c float. Both are provided by pointers
* therefore tables as well as single values are supported.
* \author PB
* \date 2014/09/25
* \todo change type to smaller - need modifications in method and Matlab code because of size
*/
enum class dataType : unsigned int
{
	DOUBLE = 1,		///< table of doubles
	FLOAT,			///< table of floats
	UNSUPPORTED		///< unsupported type
};

/**
* \class C_DumpAll
* \brief Defines main interface for saving data for Matlab
* \details Represents object associated with file defined during construction. All data are saved to
* this file according to calls to AddEntry method
* \author PB
* \date 2014/09/25
* \todo Add exeptions for errors
*/
class C_DumpAll
{
public:
	/// Main constructor
	C_DumpAll(const char* filename);
	/// Adds data of float type
	template<typename T>
	void AddEntry(const T* data, unsigned int size, const char* name);
	~C_DumpAll(void);
private:
	ofstream filedata;
	unsigned int lastpozindex;				//index ostatniego wpisu w offset
	unsigned long offset[MAX_ENTRY]; //offsety kolejnych wpisów
};

/**
* \brief Adds data to dump file
* \details Adds data on the end of file and then add entry in offsets table and modifies number of entries on the
* beginig of the file. Supports only basic data types defined in \c dataType
* \param[in] data pointer to data to be dumped to file
* \param[in] size size of the data pointed by \c data
* \param[in] name name of the entry assigned later in matlab
* \exception ios_base::badbit - on disk read error etc
* \exception ios_base::failbit - wrong conversion etc
* \exception std::logic_error - when MAX_ENTRY reached or unsuppoerted type of data
* \see dataType
*/
template<typename T>
void C_DumpAll::AddEntry(const T* data,unsigned int size, const char* name)
{
	dataType type = dataType::UNSUPPORTED;  // type of data to write
	unsigned long ile;	// number of writen bytes
	unsigned int sl;	// length of data name
	std::string name_of_type(typeid(data).name());	// copy name of T to string.
	// mapping known types
	if(name_of_type.find("float")!=string::npos)	// it is float
		type = dataType::FLOAT;
	if(name_of_type.find("double")!=string::npos)	// it is double
		type = dataType::DOUBLE;
	if(type==dataType::UNSUPPORTED)
		throw std::logic_error("Unknown Type");
	if(lastpozindex >= MAX_ENTRY)
		throw std::logic_error("Maximal entry number reached");

	sl = static_cast<unsigned int>(strlen(name));
	// we know type, now start to write data to disk
	unsigned int itype = static_cast<unsigned int>(type);
	streamoff start = filedata.tellp(); // current position in file
	filedata.write((char*)&itype, sizeof(unsigned int)); // type of data
	filedata.write((char*)&size, sizeof(unsigned int)); // number of elements in writen table
	filedata.write((char*)data, sizeof(T)*size);	// table with data
	filedata.write((char*)&sl, sizeof(unsigned int));	// length of variable name
	filedata.write(name, sizeof(char)*sl);				// name of variable saved as binary
	// how many bytes has been written
	ile = static_cast<unsigned long>(filedata.tellp() - start);
	offset[lastpozindex] = ile; //ilosc zapisanych bajtów
	lastpozindex++;
}
#endif