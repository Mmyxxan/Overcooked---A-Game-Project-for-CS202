#pragma once
#ifndef GAMEMANAGER_HPP
#define GAMEMANAGER_HPP

#include "Controller.hpp"
#include "ControllableObject.hpp"
#include "ObjectHolder.hpp"
#include "StorageHolder.hpp"
#include "KitchenHolder.hpp"
#include "Mediator.hpp"
#include "Level.hpp"
#include "Checker.hpp"
#include "Manager.hpp"
// #include "Screen.hpp"
#include "PauseGame.hpp"
#include "GameInstruction.hpp"

class GameManager
//  : public Screen 
{
    // linked list of active objects and linked list of unactive objects
    // int level; // namespace level
    // all initialized and display here;
private:
    const int screenWidth = 1400;
    const int screenHeight = 800;
    Texture background;
    // naked object or all processing, if pressed, processed keys by process of the game manager?
    // mediator
    GameInstruction* instruction;
    PauseGame* pause;
    Controller* controller;
    ControllableObject* chef;
    // TableHolder* tables;
    ObjectHolder* objects;
    StorageHolder* storage;
    KitchenHolder* kitchen;
    Mediator* mediator;
    // restaurant production with the strategy?
    // mediator, with holder.
    // CustomerHolder* customer; // customer holder assign customer to a table, and de-assign it, too.
    Level* level;
    Manager* manager;
    Checker* checker;
    Map* map;
public:
    // GameManager() : l(NULL), c(NULL), tables(NULL), storage(NULL), customer(NULL), kitchen(NULL) {

    // }
    GameManager() :
    //  Screen(),
      level(NULL), mediator(NULL), kitchen(NULL), storage(NULL), chef(NULL), manager(NULL), checker(checker), controller(NULL), map(NULL), objects(NULL), pause(nullptr), instruction(NULL) {
        // level = new Level(0);
        level = Level::getLevel();
    }
    GameManager(int l) :
    //  Screen(), 
     level(NULL), mediator(NULL), kitchen(NULL), storage(NULL), chef(NULL), manager(NULL), checker(checker), controller(NULL), map(NULL), objects(NULL), pause(nullptr), instruction(NULL) {
        // level = new Level(0);
        level = Level::getLevel();
    }
    void handleGamePause();
    void init(); 
    // {
    //     // init all things
    //     // set checker for mediator checker
    //     // registor all objects in mediator
    //     // register chef

        
    // }   
    void run();
};


#endif