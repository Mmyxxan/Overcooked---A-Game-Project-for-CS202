#pragma once
#ifndef LEVEL_HPP
#define LEVEL_HPP

#include "Libraries.hpp"
#include "Checker.hpp"

// high score

class Level {
private: // store status of game
    static Level* l;
    Checker* c;
    std::string path;
public:
    int level;
    // void loadGame();
    // void saveGame();
    static Level* getLevel() {
        return l;
    }
    void setChecker(Checker* c) {
        this -> c = c;
    }
    Level(int level) : level(level)
    , c(NULL), path("level.txt")
    {
        // c = new Checker();
    }
    // read from file, write to file
    // pass level 
    void init(Checker* c) {
        // if (!l) return;
        // l -> setChecker(c);
        setChecker(c);
        // l -> c -> start();
        c -> start();
    }
    bool run() {
        // return l -> c -> isTimeleft();
        return c -> isTimeleft();
    }
    void setLevel(int level) {
        // l -> level = level;
        this -> level = level;
    }
    void readLevel() {

    }
    void writeLevel() {

    }
    void getNextLevel() {
        // reset map, reset customer..., reset everything to start a new level... read level. void force stop for customer.
        // l -> level = l -> level + 1;
        level = level + 1;
        // l -> c -> reset();
        c -> reset();
        // l -> c -> start();
        c -> start();
        std::cout << "getting next level" << '\n';
    }
    static int getTime() {
        if (l -> level == 1) return 300;
        else if (l -> level == 2) return 300;
        return 300;
    }
    // level is a static class, static function getCustomerTime....
};

#endif