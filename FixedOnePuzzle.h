// FixedOnePuzzle.h

#ifndef FIXED_ONE_PUZZLE_H
#define FIXED_ONE_PUZZLE_H

#include "Puzzle.h"

class FixedOnePuzzle : public Puzzle {
public:
    FixedOnePuzzle();
    void fixNumberOne(); // Объявление метода фиксации числа 1
};

#endif // FIXED_ONE_PUZZLE_H


// зачем  нужно наследование ? я унаследовал класс и нигде это не использовал ™