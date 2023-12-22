#include <Screen.hpp>

// how to include header files in the most efficient way, no overlapping and errors?
// any header file pattern?
// pop state stack

void FirstGameScreen::handleEvents() {

}

void FirstGameScreen::render() {

}

void FirstGameScreen::init() {

}

void MapScreen::handleEvents() {
    if (IsKeyPressed(KEY_RIGHT)) button_iterator -> update(KEY_RIGHT);
    else if (IsKeyPressed(KEY_LEFT)) button_iterator -> update(KEY_LEFT);
    else if (IsKeyPressed(KEY_SPACE)) {
        Button* temp = nullptr;
        temp = button_iterator -> get();
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
    // button pause passed for the screen buttons
    // proxy for pause if (shouldPause()) pause();
}

void GameScreen::render() {
    game -> run();
}

void GameScreen::init() {
    // buttons created

    // game manager created
    game = new GameManager();
    game -> init();

    // instructions created
    instruction = new GameInstruction();

    // contents created
    Content* contents = new Content("game");
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
        temp = new GameScreen();
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