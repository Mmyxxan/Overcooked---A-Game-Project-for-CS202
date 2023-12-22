#include <GameManager.hpp>

void GameManager::init() {
    // init window
    // InitWindow(screenWidth, screenHeight, "OVERCOOKED");
    // SetTargetFPS(50); 

    background = LoadTexture("bg.png");

    // create
    pause = new PauseGame();
    objects = new ObjectHolder();
    map = new Map();
    chef = new ControllableObject("little_chef_overcooked_like.glb", {-3.0f, 0.0f, -1.0f}, {0.0f, 0.0f, 1.0f}, 0.0f, {8.0f, 8.0f, 8.0f});
    mediator = new Mediator(chef);
    manager = new Manager();
    checker = new Checker();
    controller = new Controller();
    kitchen = new KitchenHolder();
    storage = new StorageHolder();

    // init   
    // proxy for every functionality of kitchen or storage so that when we pause just invalidate the proxy
    objects -> init(map);
    level -> init(checker);
    manager -> init(chef, checker, map, pause);
    kitchen -> init();
    kitchen -> setMediator(mediator, map, pause);
    storage -> init();
    storage -> setMediator(mediator, map);
    controller -> registerObject(chef);

    // set Information
    chef -> setModel();
    chef -> setSpace({0.0f, 0.f, 0.0f});
    chef -> registerArea(map);
    
    std::cout << "init game successfully" << '\n';

    // remove Area
}

void GameManager::handleGamePause() {
    if (IsKeyReleased(KEY_P)) {
        pause -> toggle();
        pause -> pause();
        checker -> pause();
    }
    return;
}

void GameManager::run() {
   
            DrawTextureEx(background, {0.0f, 0.0f}, 0.0f, 1.0f, LIGHTGRAY);
            checker -> manage();
            BeginMode3D(*CameraGame::getCamera());
            
            // Draw walls
            // DrawCube({2.0f, 2.0f, 2.0f}, 3.0f, 12.0f, 6.0f, YELLOW);
    
            // Draw floor
            for (int i = 0; i < 33; i++) {
                for (int j = -2; j < 30; j++) DrawCube({(float) i - 15.0f, (float) j - 15.0f, -3.0f}, 1.0f, 1.0f, 1.0f, ((i + j) % 2 == 0) ? BROWN : WHITE);
            }
            handleGamePause();
            if (!pause -> Paused()) {
                controller -> control();

                controller -> notifyObservers();
                mediator -> notifyObjects();
                manager -> assign();
                // manager -> run();
                if (!level -> run()) {
                std::cout << checker -> score << '\n';
                level -> getNextLevel();
            }
            }
            checker -> manage(); // bring to run first to display buttons first and customer after
            level -> run();

            manager -> run();
            kitchen -> run();
            storage -> run();
            objects -> run();
            
            chef -> display();
            
            // DrawFPS(10, 10);
            EndMode3D();

            // if (!level -> run()) {
            //     std::cout << checker -> score << '\n';
            //     level -> getNextLevel();
            // }
      
}