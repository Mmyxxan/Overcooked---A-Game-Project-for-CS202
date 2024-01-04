#include <Checker.hpp>
#include <Level.hpp>

// model pool object

// attachment is like stack?

// add more ingredients to object in cooker, more wrapper, same timer.

// space will based on the position of table, or can be loaded from file.

// void manage() {

// }

void Checker::display() {
    
}

void Checker::pause() {
    if (timer) timer -> togglePause();
}

void Checker::reset() {
    score = 0;
}

// state display of storer, display food list and iterator pattern to choose

void Checker::start() {
    if (timer) delete timer;
    timer = new Timer(0, Level::getTime());
    timer -> start();
}

void Checker::manage() {
    // std::cout << "checker is processing\n";
    // draw time left and score
    system -> display();
    // DrawRectangle(277, 130, 50, 40, PINK);
    // DrawRectangle(345, 130, 50, 40, PINK);
    // DrawRectangle(307, 180, 65, 38, PINK);
    for (int i = 0; i < 3; i++) {
        if (draw[i]) delete draw[i];
    }
    draw[0] = new DrawNumber(277, 130, 50, 40, timer -> getMinute());
    draw[1] = new DrawNumber(345, 130, 50, 40, timer -> getSecond());
    draw[2] = new DrawNumber(307, 180, 65, 38, score);
    for (int i = 0; i < 3; i++) {
        if (draw[i]) draw[i] -> draw();
    }
    if (!isTimeleft()) timer -> stop();
}

bool Checker::isTimeleft() {
    return !timer || !(timer -> finish());
}

void Checker::update(const std::string description) {
    if (description == "right") {
        score += 5;
        std::cout << score << std::endl;
    }
}