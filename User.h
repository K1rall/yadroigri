#pragma once

#include <string>

class User {
private:
    std::string playerName;

public:
    User();  // Конструктор класса
    const std::string& getPlayerName() const;  // Получение имени игрока
    void setPlayerName(const std::string& name);  // Установка имени игрока
    void displayResults(double elapsedTime) const;  // Вывод результатов игры
};
