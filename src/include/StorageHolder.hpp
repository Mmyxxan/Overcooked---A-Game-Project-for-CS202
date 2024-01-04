#pragma once
#ifndef STORAGEHOLDER_HPP
#define STORAGEHOLDER_HPP

#include "Libraries.hpp"
#include "Object.hpp"
#include "Map.hpp"
#include "Mediator.hpp"
#include "Storer.hpp"

class StorageHolder {
protected:
    int num;
    Object** o;
    // Mediator* m;
public:
    StorageHolder() : o(NULL), num(10) {
        o = new Object*[num];
        for (int i = 0; i < num; i++) o[i] = nullptr;
    }
    virtual void init();
    void setMediator(Mediator* m, Map* map);
    virtual void run();
};

class StorageHolder_2 : public StorageHolder {
public:
    StorageHolder_2() : StorageHolder() {}
    void init();
    void run();
};

class StorageHolder_3 : public StorageHolder {
public:
    StorageHolder_3() : StorageHolder() {}
    void init();
    void run();
};

#endif