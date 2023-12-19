#pragma once
#ifndef MEDIATORCHECKER_HPP
#define MEDIATORCHECKER_HPP
#include "Libraries.hpp"
#include "ControllableObject.hpp"
#include "Object.hpp"
#include "Checker.hpp"

class MediatorChecker {
private:
    Object* att;
    ControllableObject* chef;
    Checker* checker;
    std::vector <Object*> obj;
public:
    MediatorChecker(): obj({}), chef(NULL), checker(NULL), att(NULL) {
        // checker = new Checker();
    }
    void setChecker(Checker* checker) {
        this -> checker = checker;
    }
    void registerObject(Object* o);
    void setChef(ControllableObject* chef);
    void deregisterObject(int id);
    void notifyObjects();
    void notifyChecker(std::string description);
    float getChefX();
    float getChefY();
    Object* getAttachment();
    void drop();
    Object* getAttachmentfrom();
};

#endif


