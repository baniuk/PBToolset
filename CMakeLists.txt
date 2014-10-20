# CMake build script for PBToolset

cmake_minimum_required (VERSION 3.0.2)

# do ustawienia
set(ROOT_PROJECT_NAME "PBToolset")

project(${ROOT_PROJECT_NAME})

# check if we are as subproject
IF (NOT COMMON_EXT_LIB_OUTPUT)
	message("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~")
	message("We are on main project level")
	message("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~")
	set(COMMON_EXT_LIB_OUTPUT ${CMAKE_SOURCE_DIR}/lib)
	set(ROOT_PROJECT_SOURCE_DIR ${CMAKE_SOURCE_DIR})
ELSE (NOT COMMON_EXT_LIB_OUTPUT)
	message("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~")
	message("We are on subproject level:")
	message("${COMMON_EXT_LIB_OUTPUT}")
	message("${ROOT_PROJECT_SOURCE_DIR}")
	message("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~")
ENDIF (NOT COMMON_EXT_LIB_OUTPUT)
# If these variables are set in env build is performed offline:
#	GTest_SVN_REPOSITORY - any value (gtest must be in /external_dep/gtest)
IF(DEFINED ENV{GTest_SVN_REPOSITORY})
	set(GTest_SVN_REPOSITORY "")
	message("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~")
	message("Use local gtest repo " External_dep/gtest)
	message("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~")
ELSE ()
	set(GTest_SVN_REPOSITORY http://googletest.googlecode.com/svn/trunk/) 
ENDIF()

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# set additional compiler flags
IF (${WIN32})
	# default RELEASE flags /DWIN32 /D_WINDOWS /W3 /GR /EHsc /MP /MD /O2 /Ob2 /D NDEBUG
	SET(EXTRA_COMPILER_FLAGS "/MP")
ELSEIF (${UNIX})
	SET(EXTRA_COMPILER_FLAGS "") 
ELSE (${WIN32})
	message(FATAL_ERROR "Wrong System")
ENDIF(${WIN32})	

# FORCE flag is necessary for updating default variable in cmake cache
# final flags results from  CMAKE_CXX_FLAGS & (CMAKE_CXX_FLAGS_DEBUG | CMAKE_CXX_FLAGS_RELEASE)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${EXTRA_COMPILER_FLAGS}" CACHE STRING "" FORCE)

# create lib output directory that can be removed by clean-build
file(MAKE_DIRECTORY lib)
# create doc output directory that can be removed by clean-build
file(MAKE_DIRECTORY doc)

enable_language(RC)

include(ExternalProject)
add_subdirectory(External_dep)

# additional subdirs are there - see src dir
add_subdirectory(src)

enable_testing()
add_subdirectory(tests)