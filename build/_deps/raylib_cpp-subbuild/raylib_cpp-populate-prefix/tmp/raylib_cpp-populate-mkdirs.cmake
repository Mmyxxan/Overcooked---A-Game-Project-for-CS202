# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "D:/cs163/Overcooked---A-Game-Project-for-CS202/build/_deps/raylib_cpp-src"
  "D:/cs163/Overcooked---A-Game-Project-for-CS202/build/_deps/raylib_cpp-build"
  "D:/cs163/Overcooked---A-Game-Project-for-CS202/build/_deps/raylib_cpp-subbuild/raylib_cpp-populate-prefix"
  "D:/cs163/Overcooked---A-Game-Project-for-CS202/build/_deps/raylib_cpp-subbuild/raylib_cpp-populate-prefix/tmp"
  "D:/cs163/Overcooked---A-Game-Project-for-CS202/build/_deps/raylib_cpp-subbuild/raylib_cpp-populate-prefix/src/raylib_cpp-populate-stamp"
  "D:/cs163/Overcooked---A-Game-Project-for-CS202/build/_deps/raylib_cpp-subbuild/raylib_cpp-populate-prefix/src"
  "D:/cs163/Overcooked---A-Game-Project-for-CS202/build/_deps/raylib_cpp-subbuild/raylib_cpp-populate-prefix/src/raylib_cpp-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "D:/cs163/Overcooked---A-Game-Project-for-CS202/build/_deps/raylib_cpp-subbuild/raylib_cpp-populate-prefix/src/raylib_cpp-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "D:/cs163/Overcooked---A-Game-Project-for-CS202/build/_deps/raylib_cpp-subbuild/raylib_cpp-populate-prefix/src/raylib_cpp-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
