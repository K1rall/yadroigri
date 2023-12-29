#include "Puzzle.h"
#include <iostream>
#include <random>
#include <algorithm>


bool Puzzle::isSolvable() const {
    int inversions = 0;
    for (int i = 0; i < 15; ++i) {
        for (int j = i + 1; j < 16; ++j) {
            if (board[i] != 0 && board[j] != 0 && board[i] > board[j]) {
                inversions++;
            }
        }
    }

    if (inversions % 2 == 0 && ((emptyCellIndex / 4) % 2 == 0)) {
        return true;
    }
    else if (inversions % 2 != 0 && ((emptyCellIndex / 4) % 2 != 0)) {
        return true;
    }
    else if (inversions % 2 == 0) {
        return true;
    }
    return false;
}

Puzzle::Puzzle() : boardSize(4), maxValue(boardSize* boardSize - 1), board(maxValue + 1), emptyCellIndex(maxValue) {
    for (int i = 0; i < 15; ++i) {
        board[i] = i + 1;
    }
    shuffleBoard();
}

const std::vector<int>& Puzzle::getBoard() const {
    return board;
}

void Puzzle::swapTiles(int index1, int index2) {
    std::swap(board[index1], board[index2]);
    emptyCellIndex = (board[index1] == 0) ? index1 : index2;
}

void Puzzle::setEmptyCellIndex(int index) {
    emptyCellIndex = index;
}

void Puzzle::shuffleBoard() {
    do {
        for (int i = 0; i < 15; ++i) {
            board[i] = i + 1;
        }
        board[15] = 0;

        std::random_device rd;
        std::mt19937 g(rd());

        do {
            std::shuffle(board.begin(), board.end(), g);
        } while (!isSolvable());

        for (int i = 0; i < 16; ++i) {
            if (board[i] == 0) {
                emptyCellIndex = i;
                break;
            }
        }
    } while (!isSolvable());
}

void Puzzle::printBoard() const {
    system("clear");
    for (int i = 0; i < 16; ++i) {
        if (i % 4 == 0) {
            std::cout << std::endl;
        }
        if (board[i] == 0) {
            std::cout << "   ";
        }
        else {
            printf("%2d ", board[i]);
        }
    }
    std::cout << std::endl;
}

bool Puzzle::moveTile(int tile) {
    if (tile < 1 || tile > 15) {
        return false;
    }

    int tileIndex = -1;
    int emptyCellRow = emptyCellIndex / 4;
    int emptyCellCol = emptyCellIndex % 4;

    for (int i = 0; i < 16; ++i) {
        if (board[i] == tile) {
            tileIndex = i;
            break;
        }
    }

    if (tileIndex == -1) {
        return false;
    }

    int tileRow = tileIndex / 4;
    int tileCol = tileIndex % 4;

    if ((std::abs(emptyCellRow - tileRow) == 1 && emptyCellCol == tileCol) ||
        (std::abs(emptyCellCol - tileCol) == 1 && emptyCellRow == tileRow)) {
        std::swap(board[tileIndex], board[emptyCellIndex]);
        emptyCellIndex = tileIndex;
        return true;
    }
    else {
        return false;
    }
}

bool Puzzle::isSolved() const {
    for (int i = 0; i < 15; ++i) {
        if (board[i] != i + 1) {
            return false;
        }
    }
    return true;
}

void Puzzle::resetBoard() {
    shuffleBoard();
}