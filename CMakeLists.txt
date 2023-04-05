cmake_minimum_required(VERSION 3.24)
project(Project1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(/include)
file(GLOB SOURCE_FILES *.c *.cpp)

foreach(SOURCE_PATH ${SOURCE_FILES})

    get_filename_component(EXECUTABLE_NAME ${SOURCE_PATH} NAME_WE)

    add_executable(${EXECUTABLE_NAME} ${SOURCE_PATH} include/Palindrom.cpp include/DynamicStringArray.cpp)

endforeach(SOURCE_PATH ${SOURCE_FILES})