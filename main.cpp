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
#include <Storer.hpp>
#include <Checker.hpp>
#include <GameManager.hpp>
#include <Screen.hpp>
#include <UI.hpp>

int main() {
    Screen* firstScreen = new MenuScreen();
    firstScreen -> init();

    UI* ui = new UI(firstScreen);
    ui -> init();
    ui -> run();
}

// int main() {
//     // GameManager* game;
//     // game = new GameManager();
//     // game -> init();
//     // game -> run();


//     Screen* firstScreen;
//     firstScreen = new MenuScreen();
//     firstScreen -> init();

//     InitWindow(1400, 800, "OVERCOOKED");
//     SetTargetFPS(50); 
//     while (!WindowShouldClose()) 
//     {
//         BeginDrawing();

//             ClearBackground(RAYWHITE);
//             // BeginMode3D(*CameraGame::getCamera());

//             // // Draw floor
//             // for (int i = 0; i < 33; i++) {
//             //     for (int j = -2; j < 30; j++) DrawCube({(float) i - 15.0f, (float) j - 15.0f, -3.0f}, 1.0f, 1.0f, 1.0f, ((i + j) % 2 == 0) ? BLACK : WHITE);
//             // }
            
//             firstScreen -> render();
//             firstScreen -> handleEvents();
            
//             // DrawFPS(10, 10);
//             // EndMode3D();
            
//         EndDrawing();
        
//     }
    
//     CloseWindow();      
    
//     return 0;
// }

// int main(void)
// {
//     // observer pattern for attachment
//     // raylib::Window* = new raylib::Window();
//     const int screenWidth = 1400;
//     const int screenHeight = 800;

//     InitWindow(screenWidth, screenHeight, "OVERCOOKED");

//     SetTargetFPS(50);               // Set our game to run at 60 frames-per-second
//     //--------------------------------------------------------------------------------------
//     Controller con;
//     Mediator* m;
//     // MediatorChecker* mc;
//     Manager* manager;
//     ControllableObject* chef;
//     Object* knife;
//     // Storer* pot;
//     Table* table;
//     Customer* pot;
//     Object* onion;
//     Cooker* oven;
//     chef = new ControllableObject("little_chef_overcooked_like.glb", {-3.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 1.0f}, 0.0f, {8.0f, 8.0f, 8.0f});
//     knife = new Object("dough.glb", {0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 1.0f}, 0.0f, {0.04f, 0.04f, 0.04f});
//     oven = new Cooker();
//     m = new Mediator(chef);

//     // pot = new Storer();
//     pot = new Customer(0);
//     onion = new Food("dough");
//     // mc = new MediatorChecker();
//     manager = new Manager();
//     manager -> init(chef);
//     // mc -> setChef(chef);
//     // knife transform one time and rotate just like its attach
    
//     pot -> setFile("little_chef_overcooked_like.glb");
//     pot -> setModel();
//     pot -> setAxis({0.0f, 0.0f, 1.0f});
//     pot -> setDirection(0.0f);
//     pot -> setPos({0.0f, 2.0f, 1.0f});
//     pot -> setScale({0.05f, 0.05f, 0.05f});
//     // chef -> removeArea({-1.0f, -4.0f}, 5.0f, 13.0f);
//     pot -> removeArea({0.0f, 2.0f}, 3.0f, 4.0f);
//     // pot -> setMediatorChecker(mc);
//     pot -> setSpace(pot -> getPos());

    
//     onion -> setFile("dough.glb");
//     onion -> setModel();
//     onion -> setAxis({0.0f, 0.0f, 1.0f});
//     onion -> setDirection(0.0f);
//     onion -> setPos({0.0f, 2.0f, 1.0f});
//     onion -> setScale({0.02f, 0.02f, 0.02f});
//     onion -> getModel().transform = MatrixTranslate(1.0f, 0.0f, 0.0f);
//     onion -> rotate(Axis::y, -PI/2);
//     onion -> rotate(Axis::z, -PI/2);
//     onion -> rotate(Axis::x, -PI/2);
//     onion -> rotate(Axis::y, PI);
//     onion -> rotate(Axis::z, -PI);

//     oven -> setFile("oven.glb");
//     oven -> setModel();
//     oven -> setAxis({0.0f, 0.0f, 1.0f});
//     oven -> setDirection(0.0f);
//     oven -> setPos({10.0f, -5.0f, 1.0f});
//     oven -> setScale({1.0f, 1.0f, 1.0f});
//     oven -> removeArea({oven -> getPos().x, oven -> getPos().y}, 2.0f, 2.0f);
//     oven -> setMediator(m);


//     chef -> setModel();
//     chef -> setSpace({1.0f, -2.5f, 0.0f});
//     knife -> setModel();
//     knife -> getModel().transform = MatrixTranslate(1.0f, 0.0f, 0.0f);
//     // unsigned int cnt = 0;
//     // ModelAnimation *anim = LoadModelAnimations("dough.glb", &cnt);
//     // std::cout << cnt << '\n';
//     // int aniFrameCounter = 0;

//     knife -> rotate(Axis::y, -PI/2);
//     knife -> rotate(Axis::z, -PI/2);
//     knife -> rotate(Axis::x, -PI/2);
//     knife -> rotate(Axis::y, PI);
//     knife -> rotate(Axis::z, -PI);


//     // table = new Table(2);
//     // table -> setFile("onion.glb");
//     // table -> setModel();
//     // table -> setAxis({0.0f, 0.0f, 1.0f});
//     // table -> setDirection(0.0f);
//     // table -> setPos({5.0f, 2.0f, 1.0f});
//     // table -> setScale({0.005f, 0.005f, 0.005f});
//     // table -> receive(pot);


//     con.registerObject(chef);
//     // con.registerObject(knife);
//     // chef -> attach(knife);
//     chef -> attach(onion);
//     // chef -> attach(nullptr);
    
//     // Main game loop
//     while (!WindowShouldClose())    // Detect window close button or ESC key
//     {
//         // Update
//         //----------------------------------------------------------------------------------
//         // TODO: Update your variables here
//         // if (++aniFrameCounter == cnt) {
//         //     aniFrameCounter = 0;
//         // }
//         // UpdateModelAnimation(knife -> getModel(), anim[0], aniFrameCounter);
//         //----------------------------------------------------------------------------------
//         // Draw
//         //----------------------------------------------------------------------------------
//         BeginDrawing();

//             ClearBackground(RAYWHITE);
//             BeginMode3D(*CameraGame::getCamera());
//             // Draw walls
//             // DrawCube({2.0f, 2.0f, 2.0f}, 3.0f, 12.0f, 6.0f, YELLOW);
            
//             // Draw floor
//             for (int i = 0; i < 30; i++) {
//                 for (int j = 0; j < 30; j++) DrawCube({(float) i - 15.0f, (float) j - 15.0f, -3.0f}, 1.0f, 1.0f, 1.0f, ((i + j) % 2 == 0) ? BLACK : WHITE);
//             }

//             // UpdateCamera(&camera, CAMERA_FIRST_PERSON);
//             // UpdateCamera(&camera, CAMERA_FREE);
//             // int left right behind face
//             // if (IsKeyDown('F')) camera.position = (Vector3){ 0.0f, 5.0f, 10.0f };
//             // else if (IsKeyDown('L')) camera.position = (Vector3){ 5.0f, 5.0f, 10.0f };
//             // BoundingBox bounds = GetMeshBoundingBox(chef.meshes[0]);
//             // bounds = GetMeshBoundingBox(chef.meshes[0]);
//             // camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };

//                 // BeginMode3D(camera);
//                 // switch (IsKeyDown('L'))
//                 // {
//                 //     case true:
//                 //         DrawModelEx(chef, {0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 1.0f}, -90.0f, {15.0f, 15.0f, 15.0f}, WHITE);
//                 //         break;
//                 //     default: 
//                 //         DrawModelEx(chef, {0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 1.0f}, 0.0f, {15.0f, 15.0f, 15.0f}, WHITE);
//                 //         break;
//                 // }       
//                 // DrawModel(chef, {0.0f, 0.0f, 0.0f}, 10.0f, WHITE);
//                 // if (IsKeyDown('L')) DrawModelEx(chef, {0.0f, 0.0f, 0.0f}, {0.0f, 1.0f, 0.0f}, 90.0f, 10.0f, WHITE);
//                 // DrawCube(cubePosition, 2.0f, 2.0f, 2.0f, RED);
//                 // DrawCubeWires(cubePosition, 2.0f, 2.0f, 2.0f, MAROON);
//                 // DrawGrid(10, 1.0f);
//                 // EndMode3D();

//             // DrawText("Welcome to the third dimension!", 10, 40, 20, DARKGRAY);
//             con.control();
//             con.notifyObservers();
//             m -> notifyObjects();
//             // mc -> notifyObjects();
//             // knife -> display();
//             chef -> display();
//             manager -> assign();
//             oven -> display();
//             // table -> display();
//             // pot -> display();
//             // onion -> display();
//             // std::cout << CheckCollisionBoxes(knife -> getBoundingBox(), chef -> getBoundingBox());
//             DrawFPS(10, 10);
//             EndMode3D();
//         EndDrawing();
//         //----------------------------------------------------------------------------------
//     }

//     // De-Initialization
//     //--------------------------------------------------------------------------------------
//     CloseWindow();        // Close window and OpenGL context
//     //--------------------------------------------------------------------------------------

//     return 0;
// }
