// OneMissingPuzzle.h

#ifndef ONE_MISSING_PUZZLE_H
#define ONE_MISSING_PUZZLE_H

#include "Puzzle.h"

class OneMissingPuzzle : public Puzzle {
public:
    OneMissingPuzzle();
    void removeRandomCell(); // Объявление метода удаления случайной ячейки
};

#endif // ONE_MISSING_PUZZLE_H
