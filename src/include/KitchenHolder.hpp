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
private:    
    int num;
    Object** o;
public:
    KitchenHolder() : o(NULL), num(10) {
        o = new Object*[num];
        for (int i = 0; i < num; i++) o[i] = nullptr;
    }
    void init();
    void setMediator(Mediator* m, Map* map, PauseGame* pause);
    void run();
};

#endif