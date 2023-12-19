#pragma once
#ifndef TABLEHOLDER_HPP
#define TABLEHOLDER_HPP

#include "Libraries.hpp"
#include "Table.hpp"
#include "Map.hpp"

class TableHolder {
private:
    Table** t;
    int num;
    Table* head;
public:
    TableHolder() : num(3), t(NULL), head(NULL) {
        t = new Table*[num];
        t[0] = new Table({-10.0f, -10.0f, -1.0f});
        t[1] = new Table({-2.0f, -15.0f, -1.0f});
        t[2] = new Table({6.0f, -10.0f, -1.0f}); // should bring to init
        for (int i = 0; i < num; i++) {
            t[i] -> removeArea({t[i] -> getPos().x -3.0f, t[i] -> getPos().y - 3.0f}, 6.0f, 6.0f);
        }
    }
    // TableHolder(int num) : num(num), t(NULL), head(NULL) {
    //     t = new Table[num];
    // }
    void init(Map* map);
    void manage();
    Table* get();
    // almost done
    // pos of table 1, table 2, ...
}; // load from file

#endif