#pragma once

class Counter{
private:
    int moveCount;

public:
    Counter();
    void incrementMoveCount();
    int getMoveCount() const;
    void displayMoveCount() const;
};
