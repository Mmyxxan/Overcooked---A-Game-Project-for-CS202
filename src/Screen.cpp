#include <Screen.hpp>

// how to include header files in the most efficient way, no overlapping and errors?
// any header file pattern?
// pop state stack

void GameUpScreen::handleEvents() {
    // std::cout << game -> getScore() << '\n';
    draw -> draw();
    // DrawRectangle(375, 420, 300, 300, WHITE);
    if (IsKeyPressed(KEY_SPACE)) {
        delete game;
        game = nullptr;
        Screen* temp = new MapScreen();
        setNextScreen(temp);
    }
}

void GameUpScreen::render() {
    bg -> display();
}

void GameUpScreen::init() {
    draw = new DrawScore(375, 420, 300, 300, game -> getScore(), 200, 15, RED);
    // draw -> init(game -> getScore());
    bg = new Button("bg4");
}

void PauseScreen::handleEvents() {
    if (IsKeyPressed(KEY_RIGHT)) button_iterator -> update(KEY_RIGHT);
    else if (IsKeyPressed(KEY_LEFT)) button_iterator -> update(KEY_LEFT);
    else if (IsKeyPressed(KEY_SPACE)) {
        Button* temp = nullptr;
        temp = button_iterator -> get();
        // if (temp -> getDescription() == "selectedresume") game -> pauseGame();
        // else 
        setNextScreen(createScreen(temp -> getNum()));
    }
}

void PauseScreen::render() {
    if (bg) bg -> display();
    button_iterator -> display();
    // EndMode3D();
    // BeginMode3D(*CameraGame::getCamera());
}

void PauseScreen::init() {
    button_iterator = new ButtonIterator();

    bg = new Button("bg3");

    Button* b1 = new ResumeButton();
    Button* b2 = new SettingButton();
    Button* b3 = new Exit1Button();

    button_iterator -> add(b1);
    button_iterator -> add(b2);
    button_iterator -> add(b3);

    // b1 -> update(true);
    button_iterator -> init();
}

// void FirstGameScreen::handleEvents() {

// }

// void FirstGameScreen::render() {

// }

void SecondGameScreen::init() {
    if (!game) {
        game = new SecondGame();
        game -> init();
    }
    else game -> pauseGame();
}

void FirstGameScreen::init() {
    if (!game) {
        game = new FirstGame();
        game -> init();
    }
    else game -> pauseGame();
}

void MapScreen::handleEvents() {
    if (IsKeyPressed(KEY_RIGHT)) button_iterator -> update(KEY_RIGHT);
    else if (IsKeyPressed(KEY_LEFT)) button_iterator -> update(KEY_LEFT);
    else if (IsKeyPressed(KEY_SPACE)) {
        Button* temp = nullptr;
        temp = button_iterator -> get();
        if (temp -> getNum() == CreateScreen::MenuScreen) {
            delete game;
            game = nullptr;
        }
        setNextScreen(createScreen(temp -> getNum()));
    }
}

void MapScreen::render() {
    bg -> display();
    if (button_iterator) button_iterator -> display();
}

void MapScreen::init() {
    button_iterator = new ButtonIterator();

    bg = new Button("bg2");

    Button* b1 = new FirstMap();
    Button* b2 = new SecondMap();
    Button* b3 = new ThirdMap();

    button_iterator -> add(b1);
    button_iterator -> add(b2);
    button_iterator -> add(b3);

    // b1 -> update(true);
    button_iterator -> init();
}

void ExitScreen::handleEvents() {

}

void ExitScreen::render(){
    if (game) delete game;
    game = nullptr;
    CloseWindow();
}

void ExitScreen::init() {

}

void GameScreen::handleEvents() {
    if (!game -> isTimeLeft()) {
        game -> pauseGame();
        Screen* temp = new GameUpScreen(game);
        setNextScreen(temp);
        return;
    }

    if (game -> handleGamePause()) {
        // if (!pauseScreen) {
        //     pauseScreen = new PauseScreen(game);
        //     pauseScreen -> init();
        // }
        // pauseScreen -> render();
        // pauseScreen -> handleEvents();
        Screen* temp = new PauseScreen(game);
        setNextScreen(temp);
        return;
    }
    return;
    // else {
    //     delete pauseScreen;
    //     pauseScreen = nullptr;
    // }
    // button pause passed for the screen buttons
    // proxy for pause if (shouldPause()) pause();
}

void GameScreen::render() {
    game -> run();
}

void GameScreen::init() {
    // buttons created

    // game manager created
    if (!game) {
        game = new GameManager();
        game -> init();
    }
    else game -> pauseGame();

    // instructions created
    // instruction = new GameInstruction();

    // contents created
    // Content* contents = new Content("game");
}

void MenuScreen::handleEvents() {
    // while (nextScreen != nullptr)
    // Screen -> pop();
    if (IsKeyPressed(KEY_RIGHT)) button_iterator -> update(KEY_RIGHT);
    else if (IsKeyPressed(KEY_LEFT)) button_iterator -> update(KEY_LEFT);
    else if (IsKeyPressed(KEY_SPACE)) {
        Button* temp = nullptr;
        temp = button_iterator -> get();
        setNextScreen(createScreen(temp -> getNum()));
    }
}

void MenuScreen::render() {
    bg -> display();
    if (button_iterator) button_iterator -> display();
}

void MenuScreen::init() {
    button_iterator = new ButtonIterator();

    bg = new Button("bg1");
    bg -> setPos({0.0f, 0.0f});

    Button* b1 = new StartButton();
    b1 -> setPos({0.0f, 0.0f});
    Button* b2 = new SettingButton();
    Button* b3 = new ExitButton();

    button_iterator -> add(b1);
    button_iterator -> add(b2);
    button_iterator -> add(b3);

    // b1 -> update(true);
    button_iterator -> init();
}

Screen* Screen::createScreen(int screen) {
    Screen* temp = nullptr;
    switch (screen)
    {
    case CreateScreen::GameScreen :
        // temp = new GameScreen();
        temp = new MapScreen();
        break;
    case CreateScreen::ExitScreen :
        temp = new ExitScreen();
        break;
    case CreateScreen::FirstGameScreen :
        // temp = new FirstGameScreen();
        temp = new GameScreen(game);
        break;
    case CreateScreen::MenuScreen :
        temp = new MenuScreen();
        break;
    case CreateScreen::SecondGameScreen :
        temp = new FirstGameScreen(game);
        break;
    case CreateScreen::ThirdGameScreen :
        temp = new SecondGameScreen(game);
        break;
    default:
        // temp = new MenuScreen();
        temp = nullptr;
        break;
    }
    return temp;
}

void Screen::handleEvents() {

}

void Screen::setNextScreen(Screen* nextScreen) {
    this -> nextScreen = nextScreen;
}

Screen* Screen::getNextScreen() {
    return nextScreen;
}

void Screen::handleGamePause() {

}

void Screen::init() {
    
}

void Screen::render() {
    
}