#pragma once
#ifndef SHAREDRESOURCES_HPP
#define SHAREDRESOURCES_HPP

#include "Libraries.hpp"

class SharedResources {
    // map hash map
private:
    int num;
    static SharedResources* sr;
    Font customer_font;
    SharedResources() : num(0) {
        init();
    }
    void init() {
        customer_font = LoadFont("BeautifulEveryTime-Dg4m.ttf");
    }
public:
    Font getCustomerFont() {
        return customer_font;
    }
    static SharedResources* getResources() {
        if (!sr) sr = new SharedResources();
        return sr;
    }
};

#endif