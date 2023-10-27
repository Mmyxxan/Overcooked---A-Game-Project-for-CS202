cmake_minimum_required(VERSION 3.14)
project(src)

file(GLOB MY_FILES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
add_library(myexe ${MY_FILES})
# Specify the location of header files
target_include_directories(myexe PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(myexe PUBLIC raylib raylib_cpp Lib)