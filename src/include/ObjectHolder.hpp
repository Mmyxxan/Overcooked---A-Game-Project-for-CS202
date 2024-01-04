#pragma once
#ifndef OBJECTHOLDER_HPP
#define OBJECTHOLDER_HPP

#include "Libraries.hpp"
#include "Object.hpp"
#include "Map.hpp"
#include "PauseGame.hpp"

class ObjectHolder {
protected:
    int num;
    Object** obj;
public:
    ObjectHolder() : num(30), obj(NULL) {
        obj = new Object*[num];
        for (int i = 0; i < num; i++) obj[i] = nullptr;
    }
    virtual void init(Map* map);
    void run();
};

class ObjectHolder_2 : public ObjectHolder {
public:
    void init(Map* map);
};

class ObjectHolder_3 : public ObjectHolder {
public:
    void init(Map* map);
};

#endif