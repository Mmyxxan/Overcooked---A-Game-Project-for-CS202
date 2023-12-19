#pragma once
#include "raylib.h"
#include "raylib-cpp.hpp"
#include <utility>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>
#include <thread>
#include <atomic>
#include <queue>
#include <set>
#ifndef LIBRARIES_HPP
#define LIBRARIES_HPP

// load file class, foodholder, samplefood holder


namespace Axis {
    const Vector3 Ox = {1.0f, 0.0f, 0.0f};
    const Vector3 Oy = {0.0f, 1.0f, 0.0f};
    const Vector3 Oz = {0.0f, 0.0f, 1.0f};
    const char x = 'x';
    const char y = 'y';
    const char z = 'z';
};

namespace State {
    const int rest = 0;
    const int activated = 1;
    const int functioning = 2;
    const int invalid = 3;
    const int outdated = 4;
    const int open = 5;
}

namespace Customers {
    const int time = 100; // seconds
    const int outdated = 4;
}

#endif