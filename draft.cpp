#include "raylib.h"
#include "raylib-cpp.hpp"
#include <iostream>
#include <object.hpp>

using namespace std;

enum Direction { UP = 180, DOWN = 0, LEFT = 270, RIGHT = 90 };

int getDirection() {
    int keyPressed = 0;
    if (IsKeyDown(KEY_W)) keyPressed = KEY_W;
    else if (IsKeyDown(KEY_S)) keyPressed = KEY_S;
    else if (IsKeyDown(KEY_A)) keyPressed = KEY_A;
    else if (IsKeyDown(KEY_D)) keyPressed = KEY_D;
    return keyPressed;
}

void controller(Model *model, int &curDirection, Vector3 &modelPos) {
    int keyPressed = getDirection();
    
    if (keyPressed) {
        switch (keyPressed) {
            case KEY_W:
                model->transform = MatrixMultiply(MatrixRotateZ((UP - curDirection) * DEG2RAD), model->transform);
                curDirection = UP;
                modelPos.z -= 0.02f;
                break;
            case KEY_A:
                model->transform = MatrixMultiply(MatrixRotateZ((LEFT - curDirection) * DEG2RAD), model->transform);
                curDirection = LEFT;
                modelPos.x -= 0.02f;
                break;
            case KEY_S:
                model->transform = MatrixMultiply(MatrixRotateZ((DOWN - curDirection) * DEG2RAD), model->transform);
                curDirection = DOWN;
                modelPos.z += 0.02f;
                break;
            case KEY_D:
                model->transform = MatrixMultiply(MatrixRotateZ((RIGHT - curDirection) * DEG2RAD), model->transform);
                curDirection = RIGHT;
                modelPos.x += 0.02f;
                break;
        }
    }
}

void draw() {
    for(int i = -10; i <= 10; ++i) {
        for(int j = -10; j <= 10; ++j) {
            DrawCube((Vector3){i, -1, j}, 1, 1, 1, (i + j) % 2 ? BLACK : RAYWHITE);
        }
    }
}

int main(void)
{
    Object2D *obj = new Object2D();
    // Initialize Raylib
    InitWindow(1400, 800, "Cooking");

    Camera3D camera = { 0 };
    camera.position = (Vector3){ 0.0f, 10.0f, 10.0f };
    camera.target = (Vector3){ 0.0f, 1.8f, 0.0f };
    camera.up = (Vector3){ 0.0f, 20.0f, 0.0f };
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    Model model = LoadModel("../resources/kirby.glb");
    model.transform = MatrixTranslate(0, 1, 0); // Set the initial position of the model
    Vector3 modelPos = {0, 0.01f, 0};
    Model model2 = LoadModel("../resources/Chef.glb");

    // unsigned int animsCount = 0;
    // unsigned int animsIdx = 0;
    // unsigned int animCurrentFrame = 0;
    // ModelAnimation *animChef = LoadModelAnimations("../resources/models/little_chef_overcooked_like.glb", &animsCount);

    // Main game loop
    model.transform = MatrixMultiply(MatrixRotateX(-PI/2), model.transform);
    int curDirection = 0;
    while (!WindowShouldClose())
    {
        Vector3 oldModelPos = modelPos;
        controller(&model, curDirection, modelPos);
        camera.target = modelPos;
        camera.position = Vector3Add(camera.position, Vector3Subtract(modelPos, oldModelPos));
        
        // UpdateModelAnimation(model, animChef[animsIdx], animCurrentFrame);

        BeginDrawing();
        ClearBackground(BLACK);

        BeginMode3D(camera);

            // Draw the model with the updated transformation matrix
            draw();
            // Draw the wall around the map
            Color wallColor = { 228, 112, 37, 255 };
            DrawCube((Vector3){-11, 0, 0}, 1, 10, 21, wallColor);
            DrawCube((Vector3){11, 0, 0}, 1, 10, 21, wallColor);
            DrawCube((Vector3){0, 0, -11}, 21, 10, 1, wallColor);
            DrawCube((Vector3){0, 0, 11}, 21, 10, 1, wallColor);

            DrawModel(model2, (Vector3){0, 0, 0}, 0.05f, WHITE);
            DrawModel(model, modelPos, 0.05f, WHITE);

        EndMode3D();

        EndDrawing();
    }

    // Unload model and close Raylib
    UnloadModel(model);
    CloseWindow();

    return 0;
}
// y
//   x
// z