#pragma once
#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "Libraries.hpp"
#include "ModelFactory.hpp"

// pause button, <> arrow keys of fridge iterator must be associated with the controller
// composition of keys controlled, ctrl + A? by controller 

class Button {
protected:
    int num;
    Texture* button;
    Vector2 position;
    Color color;
    std::string description;
public:
    Button() : button(NULL), description(""), position({0.0f, 0.0f}), color(WHITE), num(-1) {}
    Button(std::string description) : description(description), button(NULL), position({0.0f, 0.0f}), color(WHITE), num(-1) {}
    virtual void setTexture();
    void setPos(Vector2 position);
    void setNum(int num);
    int getNum();
    virtual void display();
    virtual std::string getFile();
    virtual std::string getDescription();
    virtual void trigger();
    virtual bool Selected();
    virtual void update(bool isSelected);
    // delegate display if chosen onto every subclass of button, the manager/ screen do not need to hold how every button will be displayed just because it knows which button is chosen, it sends this information to all the button, that if itself is chosen 
};

class SelectedButton : public Button {
private:
    bool isSelected;
public:
    SelectedButton() : Button(), isSelected(false) {}
    SelectedButton(std::string description) : Button(description), isSelected(false) {}
    void update(bool isSelected);
    // void select();
    // void deselect();
    void trigger();
    bool Selected();
    std::string getDescription();
};

class StartButton : public SelectedButton {
public:
    StartButton() : SelectedButton("start") {
        setNum(0);
    }
    void trigger();
    // void display();
    // void ? what();
};

class SettingButton : public SelectedButton {
public:
    SettingButton() : SelectedButton("setting") {
        setNum(1);
    }
    void trigger();
};

class ExitButton : public SelectedButton {
public:
    ExitButton() : SelectedButton("exit") {
        setNum(2);
    }
    void trigger();
};

class FirstMap : public SelectedButton {
public:
    FirstMap() : SelectedButton("firstmap") {
        setNum(3);
    }
    void trigger();
};

class SecondMap : public SelectedButton {
public:
    SecondMap() : SelectedButton("secondmap") {
        setNum(4);
    }
    void trigger() {}
};

class ThirdMap : public SelectedButton {
public:
    ThirdMap() : SelectedButton("thirdmap") {
        setNum(5);
    }
    void trigger() {}
};

class CheckerButton : public Button {
public:
    CheckerButton() : Button("checker") {}
};

#endif