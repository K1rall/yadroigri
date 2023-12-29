#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <iomanip>

class Puzzle {
private:
    const int boardSize;   // Размер доски
    const int maxValue;    // Максимальное значение плитки
    std::vector<int> board;
    int emptyCellIndex;

    bool isSolvable() const;

public:
    Puzzle();

    const std::vector<int>& getBoard() const;

    void swapTiles(int index1, int index2);

    void setEmptyCellIndex(int index);

    void shuffleBoard();

    void printBoard() const;

    bool moveTile(int tile);

    bool isSolved() const;

    void resetBoard();
};