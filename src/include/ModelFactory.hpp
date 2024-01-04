#pragma once
#include <Libraries.hpp>
// #include "Checker.hpp"
#ifndef MODELFACTORY_HPP
#define MODELFACTORY_HPP

// interface

class ModelFactory {
private:
    int num;
    static ModelFactory* mf;
    std::vector<std::string> files;
    Model** models;
public:
    ModelFactory() : num(0), files({}), models(NULL) {
        files.push_back("customer3.glb");
        files.push_back("map3.glb");
        files.push_back("MA_map3.glb");
        files.push_back("MA_map2.glb");
        files.push_back("oniontomatobakeddough.glb");
        files.push_back("pepperonionionbakeddough.glb");
        files.push_back("sausagebakeddough.glb");
        files.push_back("pepperonibakeddough.glb");
        files.push_back("onionbakeddough.glb");
        files.push_back("pizza.glb");
        files.push_back("base.glb");
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

class TextureFactory {
private:
    int num;
    static TextureFactory* tf;
    std::vector<std::string> files;
    Texture** textures;
public:
    TextureFactory() : num(0), files({}), textures(NULL) {
        files.push_back("bg4.png");
        files.push_back("tomato.png");
        files.push_back("pepperoni.png");
        files.push_back("onion.png");
        files.push_back("sausage.png");
        files.push_back("dough.png");
        files.push_back("food.png");
        files.push_back("selectedresume.png");
        files.push_back("waiting.png");
        files.push_back("eating.png");
        files.push_back("selectedfirstmap.png");
        files.push_back("selectedsecondmap.png");
        files.push_back("selectedthirdmap.png");
        files.push_back("bg.png");
        files.push_back("bg1.png");
        files.push_back("bg2.png");
        files.push_back("bg3.png");
        files.push_back("checker.png");
        files.push_back("start.png");
        files.push_back("setting.png");
        files.push_back("exit.png");
        files.push_back("selectedstart.png");
        files.push_back("selectedsetting.png");
        files.push_back("selectedexit.png");
        num = files.size();
        textures = new Texture*[num];
        for (int i = 0; i < num; i++) textures[i] = nullptr;
        init();
    }
    void init();
    static TextureFactory* getTextureFactory() {
        if (!tf) tf = new TextureFactory();
        return tf;
    }
    Texture* getTexture(std::string file) {
        for (int i = 0; i < num; i++) {
            if (file == files[i]) {
                // if (file == "checker.png") std::cout << "found\n";
                return textures[i];
            }
            // map instead
        }
        // return models[0];
        return nullptr;
    }
};

#endif