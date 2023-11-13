#include <Libraries.hpp>
#include <Object.hpp>
#include <ControllableObject.hpp>
#include <Controller.hpp>
#include <CameraGame.hpp>
#include <Timer.hpp>
#include <Cooker.hpp>
#include <Area.hpp>
#include <Mediator.hpp>
#include <Food.hpp>

int main(void)
{
    // raylib::Window* = new raylib::Window();
    const int screenWidth = 1400;
    const int screenHeight = 800;

    InitWindow(screenWidth, screenHeight, "OVERCOOKED");

    SetTargetFPS(50);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------
    Controller con;
    ControllableObject* chef;
    Object* knife;
    chef = new ControllableObject("little_chef_overcooked_like.glb", {-3.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 1.0f}, 0.0f, {8.0f, 8.0f, 8.0f});
    knife = new Object("knife.glb", {-3.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 1.0f}, 0.0f, {0.04f, 0.04f, 0.04f});
    // knife transform one time and rotate just like its attach
    chef -> setModel();
    chef -> setSpace({1.0f, -2.5f, 0.0f});
    knife -> setModel();
    knife -> getModel().transform = MatrixTranslate(1.0f, 0.0f, 0.0f);

    knife -> rotate(Axis::y, -PI/2);
    knife -> rotate(Axis::z, -PI/2);
    knife -> rotate(Axis::x, -PI/2);
    knife -> rotate(Axis::y, PI);
    knife -> rotate(Axis::z, -PI);

    con.registerObject(chef);
    con.registerObject(knife);
    chef -> attach(knife);
    // chef -> attach(nullptr);
    chef -> removeArea({-1.0f, -4.0f}, 5.0f, 13.0f);
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);
            BeginMode3D(*CameraGame::getCamera());
            // Draw walls
            DrawCube({2.0f, 2.0f, 2.0f}, 3.0f, 12.0f, 6.0f, YELLOW);
            
            // Draw floor
            for (int i = 0; i < 30; i++) {
                for (int j = 0; j < 30; j++) DrawCube({(float) i - 15.0f, (float) j - 15.0f, -3.0f}, 1.0f, 1.0f, 1.0f, ((i + j) % 2 == 0) ? BLACK : WHITE);
            }

            // UpdateCamera(&camera, CAMERA_FIRST_PERSON);
            // UpdateCamera(&camera, CAMERA_FREE);
            // int left right behind face
            // if (IsKeyDown('F')) camera.position = (Vector3){ 0.0f, 5.0f, 10.0f };
            // else if (IsKeyDown('L')) camera.position = (Vector3){ 5.0f, 5.0f, 10.0f };
            // BoundingBox bounds = GetMeshBoundingBox(chef.meshes[0]);
            // bounds = GetMeshBoundingBox(chef.meshes[0]);
            // camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };

                // BeginMode3D(camera);
                // switch (IsKeyDown('L'))
                // {
                //     case true:
                //         DrawModelEx(chef, {0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 1.0f}, -90.0f, {15.0f, 15.0f, 15.0f}, WHITE);
                //         break;
                //     default: 
                //         DrawModelEx(chef, {0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 1.0f}, 0.0f, {15.0f, 15.0f, 15.0f}, WHITE);
                //         break;
                // }       
                // DrawModel(chef, {0.0f, 0.0f, 0.0f}, 10.0f, WHITE);
                // if (IsKeyDown('L')) DrawModelEx(chef, {0.0f, 0.0f, 0.0f}, {0.0f, 1.0f, 0.0f}, 90.0f, 10.0f, WHITE);
                // DrawCube(cubePosition, 2.0f, 2.0f, 2.0f, RED);
                // DrawCubeWires(cubePosition, 2.0f, 2.0f, 2.0f, MAROON);
                // DrawGrid(10, 1.0f);
                // EndMode3D();

            // DrawText("Welcome to the third dimension!", 10, 40, 20, DARKGRAY);
            con.control();
            con.notifyObservers();
            knife -> display();
            chef -> display();
            // std::cout << CheckCollisionBoxes(knife -> getBoundingBox(), chef -> getBoundingBox());
            DrawFPS(10, 10);
            EndMode3D();
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
