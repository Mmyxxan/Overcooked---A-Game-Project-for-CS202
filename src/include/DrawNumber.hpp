#pragma once
#ifndef DRAWNUMBER_HPP
#define DRAWNUMBER_HPP

#include "Libraries.hpp"

class DrawNumber {
private:
    Rectangle frame;
    std::string text;
    int number;
public:
    DrawNumber(int posX, int posY, int width, int height, int number) 
    : number(number)
    {
        frame.x = posX;
        frame.y = posY;
        frame.width = width;
        frame.height = height;
        init();
    } 
    void init();
    void draw();
};

#endif