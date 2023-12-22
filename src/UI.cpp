#include <UI.hpp>

void UI::init() {
    InitWindow(screenWidth, screenHeight, "OVERCOOKED");
    SetTargetFPS(50); 
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
    while (!WindowShouldClose()) {
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