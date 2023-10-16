# Install script for directory: D:/cs163/Overcooked---A-Game-Project-for-CS202/build/_deps/raylib_cpp-src/include

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/overcooked")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "C:/mingw64/bin/objdump.exe")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE FILE FILES
    "D:/cs163/Overcooked---A-Game-Project-for-CS202/build/_deps/raylib_cpp-src/include/AudioDevice.hpp"
    "D:/cs163/Overcooked---A-Game-Project-for-CS202/build/_deps/raylib_cpp-src/include/AudioStream.hpp"
    "D:/cs163/Overcooked---A-Game-Project-for-CS202/build/_deps/raylib_cpp-src/include/BoundingBox.hpp"
    "D:/cs163/Overcooked---A-Game-Project-for-CS202/build/_deps/raylib_cpp-src/include/Camera2D.hpp"
    "D:/cs163/Overcooked---A-Game-Project-for-CS202/build/_deps/raylib_cpp-src/include/Camera3D.hpp"
    "D:/cs163/Overcooked---A-Game-Project-for-CS202/build/_deps/raylib_cpp-src/include/Color.hpp"
    "D:/cs163/Overcooked---A-Game-Project-for-CS202/build/_deps/raylib_cpp-src/include/Font.hpp"
    "D:/cs163/Overcooked---A-Game-Project-for-CS202/build/_deps/raylib_cpp-src/include/Functions.hpp"
    "D:/cs163/Overcooked---A-Game-Project-for-CS202/build/_deps/raylib_cpp-src/include/Gamepad.hpp"
    "D:/cs163/Overcooked---A-Game-Project-for-CS202/build/_deps/raylib_cpp-src/include/Image.hpp"
    "D:/cs163/Overcooked---A-Game-Project-for-CS202/build/_deps/raylib_cpp-src/include/Material.hpp"
    "D:/cs163/Overcooked---A-Game-Project-for-CS202/build/_deps/raylib_cpp-src/include/Matrix.hpp"
    "D:/cs163/Overcooked---A-Game-Project-for-CS202/build/_deps/raylib_cpp-src/include/Mesh.hpp"
    "D:/cs163/Overcooked---A-Game-Project-for-CS202/build/_deps/raylib_cpp-src/include/Model.hpp"
    "D:/cs163/Overcooked---A-Game-Project-for-CS202/build/_deps/raylib_cpp-src/include/ModelAnimation.hpp"
    "D:/cs163/Overcooked---A-Game-Project-for-CS202/build/_deps/raylib_cpp-src/include/Mouse.hpp"
    "D:/cs163/Overcooked---A-Game-Project-for-CS202/build/_deps/raylib_cpp-src/include/Music.hpp"
    "D:/cs163/Overcooked---A-Game-Project-for-CS202/build/_deps/raylib_cpp-src/include/Ray.hpp"
    "D:/cs163/Overcooked---A-Game-Project-for-CS202/build/_deps/raylib_cpp-src/include/RayCollision.hpp"
    "D:/cs163/Overcooked---A-Game-Project-for-CS202/build/_deps/raylib_cpp-src/include/RaylibException.hpp"
    "D:/cs163/Overcooked---A-Game-Project-for-CS202/build/_deps/raylib_cpp-src/include/raylib-cpp-utils.hpp"
    "D:/cs163/Overcooked---A-Game-Project-for-CS202/build/_deps/raylib_cpp-src/include/raylib-cpp.hpp"
    "D:/cs163/Overcooked---A-Game-Project-for-CS202/build/_deps/raylib_cpp-src/include/raylib.hpp"
    "D:/cs163/Overcooked---A-Game-Project-for-CS202/build/_deps/raylib_cpp-src/include/raymath.hpp"
    "D:/cs163/Overcooked---A-Game-Project-for-CS202/build/_deps/raylib_cpp-src/include/Rectangle.hpp"
    "D:/cs163/Overcooked---A-Game-Project-for-CS202/build/_deps/raylib_cpp-src/include/RenderTexture.hpp"
    "D:/cs163/Overcooked---A-Game-Project-for-CS202/build/_deps/raylib_cpp-src/include/Shader.hpp"
    "D:/cs163/Overcooked---A-Game-Project-for-CS202/build/_deps/raylib_cpp-src/include/Sound.hpp"
    "D:/cs163/Overcooked---A-Game-Project-for-CS202/build/_deps/raylib_cpp-src/include/Text.hpp"
    "D:/cs163/Overcooked---A-Game-Project-for-CS202/build/_deps/raylib_cpp-src/include/Texture.hpp"
    "D:/cs163/Overcooked---A-Game-Project-for-CS202/build/_deps/raylib_cpp-src/include/TextureUnmanaged.hpp"
    "D:/cs163/Overcooked---A-Game-Project-for-CS202/build/_deps/raylib_cpp-src/include/Touch.hpp"
    "D:/cs163/Overcooked---A-Game-Project-for-CS202/build/_deps/raylib_cpp-src/include/Vector2.hpp"
    "D:/cs163/Overcooked---A-Game-Project-for-CS202/build/_deps/raylib_cpp-src/include/Vector3.hpp"
    "D:/cs163/Overcooked---A-Game-Project-for-CS202/build/_deps/raylib_cpp-src/include/Vector4.hpp"
    "D:/cs163/Overcooked---A-Game-Project-for-CS202/build/_deps/raylib_cpp-src/include/VrStereoConfig.hpp"
    "D:/cs163/Overcooked---A-Game-Project-for-CS202/build/_deps/raylib_cpp-src/include/Wave.hpp"
    "D:/cs163/Overcooked---A-Game-Project-for-CS202/build/_deps/raylib_cpp-src/include/Window.hpp"
    )
endif()

