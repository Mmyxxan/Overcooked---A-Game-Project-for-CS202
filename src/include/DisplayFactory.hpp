#pragma once
#ifndef DISPLAYFACTORY_HPP
#define DISPLAYFACTORY_HPP
#include "Libraries.hpp"

class DisplayFactory {
private: static DisplayFactory* df;
         DisplayFactory() {}
         // store a vector of sample set and == and return the file name
public: static DisplayFactory* getDF() {
    if (!df) df = new DisplayFactory();
    return df;
}
        std::string getFile(std::string description);
};

#endif