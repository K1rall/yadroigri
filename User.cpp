#include "User.h"
#include <iostream>

User::User() {
    // Конструктор класса User
    std::cout << "Введите ваше имя: ";
    std::getline(std::cin, playerName);
}

const std::string& User::getPlayerName() const {
    // Возвращает имя игрока
    return playerName;
}

void User::setPlayerName(const std::string& name) {
    // Устанавливает имя игрока
    playerName = name;
}

void User::displayResults(double elapsedTime) const {
    // Выводит результаты игры
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "Поздравляем, " << getPlayerName() << ", вы прошли игру!" << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "Затраченное время: " << elapsedTime << " секунд" << std::endl;
    std::cout << "----------------------------------------" << std::endl;
}
