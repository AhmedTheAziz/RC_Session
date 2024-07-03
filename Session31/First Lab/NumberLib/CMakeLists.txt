#Example 1
cmake_minimum_required(VERSION 3.9.1)
message("Hello from Sub CMAKE")

#Example 2
add_library(
    NumbersLibs
    wifi.cpp
    wifi.h 
    Numbers.cpp 
    Numbers.h
)

message("Hello from add_lib")