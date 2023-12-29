#pragma once
#include <iostream>
#include <string>

class GameLauncher {
private:
    std::string playerName;

public:
    GameLauncher();
    void startGame();
    void playGame();
};