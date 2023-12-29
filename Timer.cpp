#include "Timer.h"
#include <iomanip>

Timer::Timer() : running(false) {}

void Timer::start() {
    if (!running) {
        start_time = std::chrono::steady_clock::now();
        running = true;
    }
}

void Timer::stop() {
    if (running) {
        end_time = std::chrono::steady_clock::now();
        running = false;
    }
}

double Timer::elapsedSeconds() const {
    if (running) {
        std::chrono::duration<double> elapsed = std::chrono::steady_clock::now() - start_time;
        return elapsed.count();
    }
    else {
        std::chrono::duration<double> elapsed = end_time - start_time;
        return elapsed.count();
    }
}

void Timer::displayTimer() const {
    int totalSeconds = static_cast<int>(elapsedSeconds());

    int minutes = totalSeconds / 60;
    int seconds = totalSeconds % 60;

    std::cout << "Затраченное время: " << minutes << " минуты " << std::setw(2) << std::setfill('0') << seconds << " секунды" << std::endl;
}