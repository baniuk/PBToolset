set(LOCAL_PROJECT_NAME Geom)
project(${LOCAL_PROJECT_NAME})
# includes in source files must be relative to ./include dir. Includes specific to 
# given project are in separate subdirectories
include_directories(${PBToolset_SOURCE_DIR}/include)

add_library(${LOCAL_PROJECT_NAME} STATIC C_Point.cpp C_Vector.cpp C_Line.cpp)