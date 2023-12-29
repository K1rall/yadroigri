// FixedOnePuzzle.cpp

#include "FixedOnePuzzle.h"

FixedOnePuzzle::FixedOnePuzzle() : Puzzle() {
    fixNumberOne();
}

void FixedOnePuzzle::fixNumberOne() {
    int oneIndex = -1;
    const std::vector<int>& board = getBoard();
    for (int i = 0; i < 16; ++i) {
        if (board[i] == 1) {
            oneIndex = i;
            break;
        }
    }

    if (oneIndex != -1) {
        Puzzle::swapTiles(oneIndex, 0);
    }
}
