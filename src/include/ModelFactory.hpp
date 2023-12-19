#pragma once
#include <Libraries.hpp>
// #include "Checker.hpp"
#ifndef MODELFACTORY_HPP
#define MODELFACTORY_HPP

class ModelFactory {
private:
    int num;
    static ModelFactory* mf;
    std::vector<std::string> files;
    Model** models;
public:
    ModelFactory() : num(0), files({}), models(NULL) {
        files.push_back("cabinet.glb");
        files.push_back("decorated.glb");
        files.push_back("trash.glb");
        files.push_back("doughdough.glb");
        files.push_back("speech_bubble.glb");
        files.push_back("extractor.glb");
        files.push_back("deco1.glb");
        files.push_back("towel.glb");
        files.push_back("wall.glb");
        files.push_back("kitchentable.glb");
        files.push_back("overcooked2.glb");
        files.push_back("overwindow.glb");
        files.push_back("3DGodotRobot.glb");
        files.push_back("chef.glb");
        files.push_back("cooker.glb");
        files.push_back("customer.glb");
        files.push_back("customer1.glb");
        files.push_back("customer2.glb");
        files.push_back("dough.glb");
        files.push_back("fridge.glb");
        files.push_back("fridge1.glb");
        files.push_back("fridge2.glb");
        files.push_back("kirby.glb");
        files.push_back("knife.glb"); // chopping board display knife like cooker display timer
        files.push_back("little_chef_overcooked_like.glb");
        files.push_back("oven.glb");
        files.push_back("table.glb");
        files.push_back("timer.glb");
        num = files.size();
        models = new Model*[num];
        for (int i = 0; i < num; i++) models[i] = nullptr;
        init();
    }
    void init();
    static ModelFactory* getModelFactory() {
        if (!mf) mf = new ModelFactory();
        return mf;
    }
    Model* getModel(std::string file) {
        for (int i = 0; i < num; i++) {
            if (file == files[i]) return models[i];
        }
        // return models[0];
        return nullptr;
    }
};

#endif