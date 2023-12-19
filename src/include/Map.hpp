#pragma once
#include <Libraries.hpp>
#include "Area.hpp"
// #include "Checker.hpp"
#ifndef MAP_HPP
#define MAP_HPP

class Map {
private:
    int num;
    int cur;
    Area** areas;
public:
    Map() : areas(NULL), num(100), cur(0) {
        areas = new Area*[num];
        for (int i = 0; i < num; i++) areas[i] = nullptr;
    }
    void registerArea(Area* area);
    bool Movable(float x, float y, Area* area);
};

#endif