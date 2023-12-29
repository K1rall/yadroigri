#pragma once
#include <vector>
#include <algorithm>
#include <iostream>

class PersonalRecord {
private:
    std::vector<double> records;
    const int maxRecords; // Максимальное количество записей

public:
    PersonalRecord();
    void updateRecord(double time);
    void displayRecords() const;
};