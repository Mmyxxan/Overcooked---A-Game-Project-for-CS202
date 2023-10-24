#include "raylib.h"

int main(void)
{
    const int screenWidth = 1940;
    const int screenHeight = 900;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - 3d camera mode");

    // Define the camera to look into our 3d world
    Camera3D camera = { 0 };
    camera.position = (Vector3){ 0.0f, -30.0f, 20.0f };  // Camera position
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };      // Camera looking at point
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
    camera.fovy = 45.0f;                                // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE;             // Camera mode type

    Vector3 cubePosition = { 0.0f, 0.0f, 0.0f };
    Model chef = LoadModel("little_chef_overcooked_like.glb");
    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

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
            // UpdateCamera(&camera, CAMERA_FIRST_PERSON);
            // UpdateCamera(&camera, CAMERA_FREE);
            // int left right behind face
            // if (IsKeyDown('F')) camera.position = (Vector3){ 0.0f, 5.0f, 10.0f };
            // else if (IsKeyDown('L')) camera.position = (Vector3){ 5.0f, 5.0f, 10.0f };
            
            
            // BoundingBox bounds = GetMeshBoundingBox(chef.meshes[0]);
            // bounds = GetMeshBoundingBox(chef.meshes[0]);
            // camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };
            BeginMode3D(camera);
            switch (IsKeyDown('L'))
            {
                case true:
                    DrawModelEx(chef, {0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 1.0f}, -90.0f, {15.0f, 15.0f, 15.0f}, WHITE);
                    break;
                default: 
                    DrawModelEx(chef, {0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 1.0f}, 0.0f, {15.0f, 15.0f, 15.0f}, WHITE);
                    break;
            }       
                // DrawModel(chef, {0.0f, 0.0f, 0.0f}, 10.0f, WHITE);
                // if (IsKeyDown('L')) DrawModelEx(chef, {0.0f, 0.0f, 0.0f}, {0.0f, 1.0f, 0.0f}, 90.0f, 10.0f, WHITE);
                // DrawCube(cubePosition, 2.0f, 2.0f, 2.0f, RED);
                // DrawCubeWires(cubePosition, 2.0f, 2.0f, 2.0f, MAROON);
                // DrawGrid(10, 1.0f);
            EndMode3D();

            DrawText("Welcome to the third dimension!", 10, 40, 20, DARKGRAY);

            DrawFPS(10, 10);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
