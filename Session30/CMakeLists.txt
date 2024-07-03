#Example 1
##cmake_minimum_required(VERSION 3.9.1)
##project(CMakeHello) #name of the project

### ${CMAKE_BINARY_DIR} #current directory

##set(CMAKE_CXX_STANDARD 14) #setting varibales version of c/c++ 
##message("the out Path is "${EXECUTABLE_OUTPUT_PATH}) ## Show path
## ##message("Adding EXE. ") # ==Echo
##add_executable(CMakeHello testDate.cpp Date.cpp) ## exe. file with the name of the project and dependincies

 # Example 2
### clear must be made manual from cmd ( rm -r *) /( rm *)
### Minimum required lines to compile.
##cmake_minimum_required(VERSION 3.9.1)
##add_executable(CMakeHello testDate.cpp Date.cpp)

#Example 3 (Embedded Libraries)
cmake_minimum_required(VERSION 3.9.1)
project(NumbersApp)
add_executable(NumbersApp 
main.cpp
NumberLib/Numbers.cpp
NumberLib/Numbers.h)
