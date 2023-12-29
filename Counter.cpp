#include "Counter.h"
#include <iostream>

Counter::Counter() : moveCount(0) {}

void Counter::incrementMoveCount() {
    moveCount++;
}

int Counter::getMoveCount() const {
    return moveCount;
}

void Counter::displayMoveCount() const {
    std::cout << "Количество ходов: " << moveCount << std::endl;
}