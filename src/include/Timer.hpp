#pragma once
#include "Libraries.hpp"

class Timer {
public:
    Timer(int minutes, int seconds) : totalSeconds(minutes * 60 + seconds), isRunning(true), timerThread(NULL), _minute(seconds / 60), _second(seconds % 60), isPaused(false) {
        if (totalSeconds <= 0) {
            std::cerr << "Invalid timer duration." << std::endl;
            isRunning.store(false);
        }
    }
    void togglePause();
    int getTimePaused();
    void pause();
    bool isStopped();
    int getMinute();
    int getSecond();
    bool finish();
    void start();
    void stop();
    bool TimerisRunning();
private:
    bool isPaused;
    std::thread* timerThread;
    int totalSeconds;
    std::atomic<bool> isRunning;
    int _minute;
    int _second;

    void countdown();
};

// int main() {
//     int minutes = 5;
//     int seconds = 0;

//     Timer timer(minutes, seconds);
//     timer.start();

//     // Your GUI rendering loop at 60 FPS goes here

//     // Ensure the timer thread is stopped when the program exits
//     timer.stop();

//     return 0;
// }
