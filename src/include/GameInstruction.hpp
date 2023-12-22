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
    Content(std::string description) : description(description) {} 
    void setDescription(std::string description);
    std::string getDescription();
    // display instruction and end automatically, pop stack to display, end display continuing pop stack, push stack from 3rd party e.g. game manager
    // sth else
};

class GameInstruction {
private:
    Texture** frames;
    Content* content;
public:
    GameInstruction() : content(NULL), frames(NULL) {

    }
    void start() {} void end() {} // start display finish and end, when call display again call start again
    void setContent(Content* content);
    void changeContent();
    Content* getContent();
    void display(bool isTriggered); // while standing in customer's area timer and new time 1s continuing while in customer
    void auto_display(); // continue by frame and time for each frame and end itself

};

#endif