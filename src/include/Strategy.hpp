#pragma once
#ifndef STRATEGY_HPP
#define STRATEGY_HPP

#include "Manager.hpp"

class ChapterStrategy {
private:
    Manager* manager;
public:
    ChapterStrategy(Manager* manager) : manager(manager) {

    }
    virtual void assign();
};

#endif