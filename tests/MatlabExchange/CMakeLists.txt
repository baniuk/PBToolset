# rzeczy do zmiany
set(LOCAL_PROJECT_NAME MatlabExchange_Test)

project(${LOCAL_PROJECT_NAME})
# get directory prefixes for libs and includes of external tools
ExternalProject_Get_Property(googletest binary_dir)
set(GTest_LIB ${binary_dir})
ExternalProject_Get_Property(googletest source_dir)
set(GTest_SRC ${source_dir}) 

include_directories(${GTest_SRC}/include ${PBToolset_SOURCE_DIR}/include)
add_executable(${LOCAL_PROJECT_NAME} C_MatlabExchange_Tests.cpp)
# gtest specific
target_compile_options(${LOCAL_PROJECT_NAME} PUBLIC -D_VARIADIC_MAX=10)
# zmienna COMMON_EXT_LIB_OUTPUT jest ustawiana albo na poczatku albo pochodzi z nadrzędnego projektu i dotyczy tylko zewnętrznych i wspólnych projektów
target_link_libraries(${LOCAL_PROJECT_NAME} ${COMMON_EXT_LIB_OUTPUT}/gtest${CMAKE_FIND_LIBRARY_SUFFIXES} ${COMMON_EXT_LIB_OUTPUT}/gtest_main${CMAKE_FIND_LIBRARY_SUFFIXES})

# linking with tested lib
target_link_libraries(${LOCAL_PROJECT_NAME} MatlabExchange)
add_dependencies(${LOCAL_PROJECT_NAME} googletest MatlabExchange)
add_test(${LOCAL_PROJECT_NAME} ${LOCAL_PROJECT_NAME})