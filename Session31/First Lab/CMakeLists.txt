cmake_minimum_required(VERSION 3.9.1)
project(HELLOPROJ)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED true) ##make sure variable exists

add_subdirectory(${CMAKE_SOURCE_DIR}/NumberLib) ## ==add_subdirectory(NumberLib) must be the same as the lib file
###^^ ${CMAKE_SOURCE_DIR}/NumberLib for flexible search for the file in ant device

message("Path To Our CMAKE: "${CMAKE_SOURCE_DIR})


#Example if exists
if(EXISTS ${CMAKE_SOURCE_DIR}/main.cpp)
message(STATUS "File Exists!!") ## WARNING, STATUS, FATAL_ERROR
else()
message(FATAL_ERROR "File doesn't Exist!!!")
endif()

set(
    SRC_FILES
    main.cpp
    ${CMAKE_SOURCE_DIR}/NumberLib/Numbers.cpp 
    )
    add_executable(NumConvert ${SRC_FILES})
    
    target_link_libraries(NumConvert PRIVATE ${CMAKE_SOURCE_DIR}/NumberLib) ##PRIVATE from the same folder!!
    
    target_include_directories(NumConvert PUBLIC ${CMAKE_SOURCE_DIR}/NumberLib) ## PUBLIC from any folder on the device!!
    ## ^^ include files in dir to my project, 
##target_link_libraries(NumConvert PRIVATE ${CMAKE_SOURCE_DIR}/gmock) ##link google test library