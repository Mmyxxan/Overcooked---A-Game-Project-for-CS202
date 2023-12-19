#include <ModelFactory.hpp>

ModelFactory* ModelFactory::mf = nullptr;

void ModelFactory::init() { 
    std::cerr << num << std::endl;
    for (int i = 0; i < num; i++) {
        // models[i] = LoadModel("chef.glb");
        // models[i] = new Model();
        // LoadModel(files[i].c_str());
        // LoadTexture("Pizza Ingredients Texture.png");
        // not done initializing raylib so it crashed
        models[i] = new Model(LoadModel(files[i].c_str()));
        if (files[i] == "fridge2.glb") {
            models[i] -> transform = MatrixMultiply(MatrixRotateY(PI/2), models[i] -> transform);
            models[i] -> transform = MatrixMultiply(MatrixRotateX(-PI/2), models[i] -> transform);
            models[i] -> transform = MatrixMultiply(MatrixRotateY(PI/2), models[i] -> transform);
            models[i] -> transform = MatrixMultiply(MatrixRotateX(-PI/2), models[i] -> transform);
        }
    }
}