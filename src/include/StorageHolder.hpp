#pragma once
#ifndef STORAGEHOLDER_HPP
#define STORAGEHOLDER_HPP

#include "Libraries.hpp"
#include "Object.hpp"
#include "Map.hpp"
#include "Mediator.hpp"
#include "Storer.hpp"

class StorageHolder {
private: 
    int num;
    Object** o;
    // Mediator* m;
public:
    StorageHolder() : o(NULL), num(10) {
        o = new Object*[num];
        for (int i = 0; i < num; i++) o[i] = nullptr;
    }
    void init();
    void setMediator(Mediator* m, Map* map);
    void run();
};

#endif