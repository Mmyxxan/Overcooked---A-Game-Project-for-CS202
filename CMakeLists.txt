cmake_minimum_required(VERSION 3.14)
project(overcooked)

set(OSBit 32)
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(OSBit 64)
endif()

# raylib
find_package(raylib QUIET)
if (NOT raylib_FOUND)
    include(FetchContent)
    FetchContent_Declare(
        raylib
        GIT_REPOSITORY https://github.com/raysan5/raylib.git
        GIT_TAG 4.5.0
    )
    FetchContent_MakeAvailable(raylib)
endif()

# raylib-cpp
find_package(raylib_cpp QUIET)
if (NOT raylib_cpp_FOUND)
    include(FetchContent)
    FetchContent_Declare(
        raylib_cpp
        GIT_REPOSITORY https://github.com/RobLoach/raylib-cpp.git
        GIT_TAG v4.5.1
    )
    FetchContent_MakeAvailable(raylib_cpp)
endif()

# This is about storage:
set(AllOutDir "${CMAKE_SOURCE_DIR}/bin/${CMAKE_SYSTEM_NAME}${OSBit}/${CMAKE_BUILD_TYPE}")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${AllOutDir}/StaticLibs)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${AllOutDir}/SharedLibs)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${AllOutDir})

set(SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/assets")
set(DESTINATION_DIR "${AllOutDir}")
file(GLOB LIST_FILES "${SOURCE_DIR}/*")

foreach(file ${LIST_FILES})
    file(COPY "${file}" DESTINATION "${DESTINATION_DIR}")
endforeach()

# This is the main part:
set(SOURCES main.cpp)
add_executable(${PROJECT_NAME} ${SOURCES})
# target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/include)
# Create an INTERFACE library target for your header-only library
add_library(Lib INTERFACE)

# Specify the include directory where your library headers are located
target_include_directories(Lib INTERFACE ${CMAKE_SOURCE_DIR}/src/include)
add_subdirectory(src)
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 11)
target_link_libraries(${PROJECT_NAME} PUBLIC raylib raylib_cpp myexe Lib)

# Web Configurations
if (${PLATFORM} STREQUAL "Web")
    # Tell Emscripten to build an example.html file.
    set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX ".html")

    # Required linker flags for using Raylib with Emscripten
    target_link_options(${PROJECT_NAME} PRIVATE -sEXPORTED_FUNCTIONS=['_main','_malloc'] -sEXPORTED_RUNTIME_METHODS=ccall -sUSE_GLFW=3)
endif()
