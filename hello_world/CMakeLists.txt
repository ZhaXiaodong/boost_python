cmake_minimum_required (VERSION 2.6)

project(boost_python_test )

find_package(PythonLibs 2.7 REQUIRED )
include_directories( ${PYTHON_INCLUDE_DIRS} )

find_package(Boost 1.61.0 COMPONENTS python REQUIRED )
include_directories( ${Boost_INCLUDE_DIR} )

# build our library
add_library(greet SHARED greet.cpp )

# build the wrapper library that wraps our library
add_library(greet_ext SHARED greet_ext.cpp )
target_link_libraries(greet_ext ${Boost_LIBRARIES} greet)

# don't prepend wrapper library name with lib
set_target_properties( greet_ext PROPERTIES PREFIX "" )