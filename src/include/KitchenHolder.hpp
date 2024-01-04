#pragma once
#ifndef KITCHENHOLDER_HPP
#define HOLDER_HPP

#include "Libraries.hpp"
#include "Object.hpp"
#include "Mediator.hpp"
#include "Map.hpp"
#include "Cooker.hpp"
#include "PauseGame.hpp"

class KitchenHolder {
protected:
    int num;
    Object** o;
public:
    KitchenHolder() : o(NULL), num(10) {
        o = new Object*[num];
        for (int i = 0; i < num; i++) o[i] = nullptr;
    }
    virtual void init();
    void setMediator(Mediator* m, Map* map, PauseGame* pause);
    virtual void run();
};

class KitchenHolder_2 : public KitchenHolder {
public:
    KitchenHolder_2() : KitchenHolder() {
    }
    void init();
    void run();
};

class KitchenHolder_3 : public KitchenHolder {
public:
    KitchenHolder_3() : KitchenHolder() {

    }
    void init();
    void run();
};

#endif