#include <GameManager.hpp>

void SecondGame::init() {
    // change position of objects by constructor, or going to its initial constructor where I have put the desired position, change it to load file method to change initial position
    background = LoadTexture("bg.png");

    // set Camera focus
    CameraGame::getCamera() -> target = (Vector3){ -3.0f, 7.0f, -2.5f };

    // set level
    level -> setLevel(3);

    // create
    pause = new PauseGame();
    objects = new ObjectHolder_3();
    map = new Map();
    chef = new ControllableObject("little_chef_overcooked_like.glb", {2.0f, 2.0f, -8.0f}, {0.0f, 0.0f, 1.0f}, 0.0f, {9.0f, 9.0f, 9.0f});
    mediator = new Mediator(chef);
    manager = new Manager_3();
    checker = new Checker();
    controller = new Controller();
    kitchen = new KitchenHolder_3();
    storage = new StorageHolder_3();

    // init   
    // proxy for every functionality of kitchen or storage so that when we pause just invalidate the proxy
    objects -> init(map);
    // if (!level) level = new Level(1);
    // else level -> setLevel(1);
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
}

void SecondGame::run() {
    DrawTextureEx(background, {0.0f, 0.0f}, 0.0f, 1.0f, LIGHTGRAY);
    checker -> manage();
    BeginMode3D(*CameraGame::getCamera());
    
    // Draw walls
    // DrawCube({2.0f, 2.0f, 2.0f}, 3.0f, 12.0f, 6.0f, YELLOW);

    // Draw floor
    // for (int i = 0; i < 33; i++) {
    //     for (int j = -2; j < 30; j++) DrawCube({(float) i - 15.0f, (float) j - 15.0f, -3.0f}, 1.0f, 1.0f, 1.0f, ((i + j) % 2 == 0) ? BROWN : WHITE);
    // }
    // handleGamePause();

    // checker -> manage(); // bring to run first to display buttons first and customer after
    level -> run();

    if (!pause -> Paused()) {
        controller -> control();

        controller -> notifyObservers();
        mediator -> notifyObjects();


        manager -> assign();


        // manager -> run();

        // if (!level -> run()) {
        // std::cout << checker -> score << '\n';
        // level -> getNextLevel();
        // }
    }
    

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

void FirstGame::init() {
    // change position of objects by constructor, or going to its initial constructor where I have put the desired position, change it to load file method to change initial position
    background = LoadTexture("bg.png");

    // set Camera focus
    CameraGame::getCamera() -> target = (Vector3){ -3.0f, 7.0f, -2.5f };

    // set level
    level -> setLevel(2);

    // create
    pause = new PauseGame();
    objects = new ObjectHolder_2();
    map = new Map();
    chef = new ControllableObject("little_chef_overcooked_like.glb", {-3.0f, 7.0f, -2.5f}, {0.0f, 0.0f, 1.0f}, 0.0f, {12.0f, 12.0f, 12.0f});
    mediator = new Mediator(chef);
    manager = new Manager_2();
    checker = new Checker();
    controller = new Controller();
    kitchen = new KitchenHolder_2();
    storage = new StorageHolder_2();

    // init   
    // proxy for every functionality of kitchen or storage so that when we pause just invalidate the proxy
    objects -> init(map);
    // if (!level) level = new Level(1);
    // else level -> setLevel(1);
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

void FirstGame::run() {
    DrawTextureEx(background, {0.0f, 0.0f}, 0.0f, 1.0f, LIGHTGRAY);
    checker -> manage();
    BeginMode3D(*CameraGame::getCamera());
    
    // Draw walls
    // DrawCube({2.0f, 2.0f, 2.0f}, 3.0f, 12.0f, 6.0f, YELLOW);

    // Draw floor
    // for (int i = 0; i < 33; i++) {
    //     for (int j = -2; j < 30; j++) DrawCube({(float) i - 15.0f, (float) j - 15.0f, -3.0f}, 1.0f, 1.0f, 1.0f, ((i + j) % 2 == 0) ? BROWN : WHITE);
    // }
    // handleGamePause();

    // checker -> manage(); // bring to run first to display buttons first and customer after
    level -> run();

    if (!pause -> Paused()) {
        controller -> control();

        controller -> notifyObservers();
        mediator -> notifyObjects();
        manager -> assign();
        // manager -> run();

        // if (!level -> run()) {
        // std::cout << checker -> score << '\n';
        // level -> getNextLevel();
        // }
    }
    

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

void GameManager::init() {
    // init window
    // InitWindow(screenWidth, screenHeight, "OVERCOOKED");
    // SetTargetFPS(50); 
    background = LoadTexture("bg.png");

    // set level
    level -> setLevel(1);

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
    // if (!level) level = new Level(1);
    // else level -> setLevel(1);
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

void GameManager::pauseGame() {
    pause -> toggle();
    pause -> pause();
    checker -> pause();
}

bool GameManager::handleGamePause() {
    if (IsKeyPressed(KEY_LEFT_CONTROL) && !(pause -> Paused())) {
        pauseGame();
    }
    return pause -> Paused();
}

bool GameManager::isTimeLeft() {
    return level -> run();
}

int GameManager::getScore() {
    return checker -> score;
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
            // handleGamePause();

            checker -> manage(); // bring to run first to display buttons first and customer after
            level -> run();

            if (!pause -> Paused()) {
                controller -> control();

                controller -> notifyObservers();
                mediator -> notifyObjects();
                manager -> assign();
                // manager -> run();

                // if (!level -> run()) {
                // std::cout << checker -> score << '\n';
                // level -> getNextLevel();
                // }
            }
            

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