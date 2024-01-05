#include <UI.hpp>

void UI::init() {
    InitWindow(screenWidth, screenHeight, "OVERCOOKED");
    SetTargetFPS(60); 
}

void UI::handle() {
    if (currentScreen -> getNextScreen()) {
        Screen* temp = currentScreen -> getNextScreen();
        temp -> init();
        delete currentScreen;
        currentScreen = temp;
    }
}

void UI::run() {
    GameAudio::getAudio();
    while (!WindowShouldClose()) {
        // GameAudio::getAudio() -> play();
        BeginDrawing();
            ClearBackground(RAYWHITE);

            // UI handle here
            handle();

            // render and handle screen here
            currentScreen -> render();
            currentScreen -> handleEvents();

            DrawFPS(10, 10);
        EndDrawing();
    }
    CloseWindow();     
}