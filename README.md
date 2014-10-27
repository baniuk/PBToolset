PBToolset
=========
Set of various common tools used in many projects.

Build and requirements
----------------------
The project is maintained by cmake and can be compiled in various ways. It can be merged to **superproject** as **ExternalProject**. It is compatibile with general *cmake-mantained* projects used by Author.

### Requirements ###
This project depends on:

 1. Google test API - which is included as **ExternalProject** and can be obtained in two ways:
  * Automatically by *cmake*  checking out from repository http://googletest.googlecode.com/svn/trunk/
  * Using local hard copy of this repo in case of working off-line. To use hard copy of *gtest* the repository must be manually cloned into `External_dep/gtest` and environmental variable `GTest_SVN_REPOSITORY` must be set to **any** value.
 2. SVN tool shoud be avaiable on system (**not local**) `%PATH%`
 3. Doxygen for documentation building (on local or system path)
 4. Graphviz package (on local or system path)

### Build ###   
The following scripts available:

 * `./clean-build.bat` - clears everything and run cmake and then make, results are in `bin` and `lib`. Runs also all tests
 * `./recreate-msvc.bat` - deletes all cmake outputs and generates MSVC projects and solution in `bin`
 * `./recreate-cmake.bat` - deletes all cmake outputs and generates MSVC makefiles in `bin`
 * `./build_doc.bat` - calls doxygen and builds doc in `doc` dir
 
### Other settings ###
To use this project as **ExternalProject** pass `ROOT_PROJECT_SOURCE_DIR` variable during calling `ExternalProject_Add` pointing to the root of **superproject**. Due to compatibility with general conception of cmake projects used by Author all static outputs will hit `ROOT/LIB` directory

Problems
--------
If using Visual Studio solution all environmental variables and paths must be set globally for user (`setx`)
