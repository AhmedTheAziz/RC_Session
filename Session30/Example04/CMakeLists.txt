
#Example 4 (static Libraries) last 10 mins of the 30's lecture..
cmake_minimum_required(VERSION 3.9.1)
#project(NumbersApp)
#target_include_directories(NumbersApp PUBLIC NumberLib) #to automatically include paths 
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
add_executable(NumbersApp 
main.cpp
NumberLib/Numbers.cpp
NumberLib/Numbers.h)
