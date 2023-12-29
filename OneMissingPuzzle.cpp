// OneMissingPuzzle.cpp

#include "OneMissingPuzzle.h"

OneMissingPuzzle::OneMissingPuzzle() : Puzzle() {
    removeRandomCell();
}

void OneMissingPuzzle::removeRandomCell() {
    int missingCellIndex = 15;  // Индекс правой нижней ячейки
    setEmptyCellIndex(missingCellIndex);
    swapTiles(missingCellIndex, 15);
}
