cmake_minimum_required(VERSION 3.4)

# set the project name and version
project(BuscaString VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)

# Add main.cpp file of project root directory as source file
set(SOURCE_FILES bs-lib/BuscaString.cpp)

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(main ${SOURCE_FILES})



