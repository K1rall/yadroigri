#include "GameLauncher.h"
#include "GameInfo.h"

GameLauncher::GameLauncher() {
    //  Конструктор по умолчанию
}

void GameLauncher::startGame() {
    GameInfo::displayGameInfo(); // Вывод информации об игре

    std::cout << "------------------------------------------------------------------------- " << std::endl;
    std::cout << "Введите ваше имя: ";
    std::getline(std::cin, playerName);

    playGame(); // Если введено "0", то игра запускается
}

void GameLauncher::playGame() {
    
     std::cout << "Игра началась для игрока " << playerName << std::endl;
}