#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <iomanip>
#include <chrono>
#include <iomanip>
#include <string>

//./build/02labpyatnashki

#include "Puzzle.h"
#include "Timer.h"
#include "PersonalRecord.h"
#include "ErrorLog.h"
#include "Counter.h"
#include "GameInfo.h"
#include "GameLauncher.h"
#include "User.h"
#include "FixedOnePuzzle.h"
#include "OneMissingPuzzle.h"

int main()
{
    setlocale(LC_ALL, "RU");
    Puzzle puzzle;
    
    Timer timer;
    
    PersonalRecord personalRecord;
    
    Counter moveCounter; 
    int userInput = 0; // Переменная для ввода пользователя
    
    GameLauncher gameLauncher;
    gameLauncher.startGame();


   
    timer.start();

    while (!puzzle.isSolved()) {
        std::cout << "Текущая доска:" << std::endl;
        puzzle.printBoard();

        // Вывод времени
        timer.displayTimer();

        // Вывод количества ходов
        moveCounter.displayMoveCount();

        // Получение корректного ввода от пользователя
        while (true) {
            std::cout << "Введите число от (1-15) для перестановки: ";
            if (!(std::cin >> userInput) || userInput < 1 || userInput > 15) {
                 std::cout << "------------------------------------------"<< std::endl;
                std::cout << "Некорректный ввод. Попробуйте снова." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                
                
            } 
            else {
                break;
            }
        }

        if (!puzzle.moveTile(userInput)) {
            std::cout << "Невозможно передвинуть число. Попробуй еще раз" << std::endl;
        } 
        
        else {
            moveCounter.incrementMoveCount(); // Увеличение счетчика ходов
        }
    }

    timer.stop();

    double elapsedTime = timer.elapsedSeconds();
    std::cout << "________________________________________" << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "Поздравляем, вы прошли игру!" << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "Затраченное время: " << elapsedTime << " секунд" << std::endl;
    std::cout << "----------------------------------------" << std::endl;

    personalRecord.updateRecord(elapsedTime);

    personalRecord.displayRecords();

    // Вывод общего количества ходов
    moveCounter.displayMoveCount();

    return 0;
}


