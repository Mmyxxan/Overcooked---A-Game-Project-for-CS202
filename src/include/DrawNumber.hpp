#pragma once
#ifndef DRAWNUMBER_HPP
#define DRAWNUMBER_HPP

#include "Libraries.hpp"
#include "SharedResources.hpp"

class DrawNumber {
protected:
    Rectangle frame;
    std::string text;
    int number;
public:
    DrawNumber(int posX, int posY, int width, int height, int number) 
    : number(number), text("")
    {
        frame.x = posX;
        frame.y = posY;
        frame.width = width;
        frame.height = height;
        init(number);
    } 
    Vector2 GetCenterPos(Font font, std::string text, float fontSize, float spacing, float x, float y, float width, float height);
    Vector2 GetCenterPos(Font font, std::string text, float fontSize, float spacing, Rectangle rect);
    void init(int number);
    virtual void draw();
};

class DrawScore : public DrawNumber {
protected:
    float fontSize;
    float spacing;
    Color color;
public:
    DrawScore(int posX, int posY, int width, int height, int number, float fontSize, float spacing, Color color) :
        fontSize(fontSize), spacing(spacing), color(color), DrawNumber(posX, posY, width, height, number)
        {
             
        }
    void draw();
};

#endif