#pragma once
#ifndef GAMEINSTRUCTION_HPP
#define GAMEINSTRUCTION_HPP

// composition with game manager to display, and which to display
// switch display on game events?, game events send contents to it and it just displays

#include "Libraries.hpp"

class Content {
private:
    // font
    // format - flyweight - intrinsic
    // contents - extrinsic
    std::string description;
public:
    Content() : description("") {

    }
    void setDescription(std::string description);
    std::string getDescription();
    // sth else
};

class GameInstruction {
private:
    Rectangle frame;
    Content* content;
public:
    GameInstruction() : content(NULL) {

    }
    void setContent(Content* content);
    void changeContent();
    Content* getContent();
    void display();
};

#endif