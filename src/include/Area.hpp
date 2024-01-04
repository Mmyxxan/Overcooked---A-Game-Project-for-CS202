#pragma once
#include "Libraries.hpp"

class Area {
private:
    bool** cell;
    int x;
    int y;
    const float BIAS = 100.0f;
    bool isControllable;
public: 
    Area(int x, int y, bool isControllable): x(x), y(y), isControllable(isControllable) {
        cell = new bool*[x];
        for (int i = 0; i < x; i++) {
            cell[i] = new bool[y];
            for (int j = 0; j < y; j++) cell[i][j] = isControllable;
        }
    }
    // void registerArea(Map* map);
    void drawArea();
    void resetArea();
    bool isInArea(float cx, float cy);
    bool isMovable(float cx, float cy);
    void removeArea(Vector2 root, float height, float width);
};

// which data structures?