#pragma once
#include <chrono>
#include <iostream>

class Timer {
private:
    std::chrono::time_point<std::chrono::steady_clock> start_time;
    std::chrono::time_point<std::chrono::steady_clock> end_time;
    bool running;

public:
    Timer();
    void start();
    void stop();
    double elapsedSeconds() const;
    void displayTimer() const;
};