#include "PersonalRecord.h"

PersonalRecord::PersonalRecord() : maxRecords(3) {
    // Инициализация записей некоторыми значениями по умолчанию
    records.push_back(0.0);
    records.push_back(0.0);
    records.push_back(0.0);
}

void PersonalRecord::updateRecord(double time) {
    records.push_back(time);
    std::sort(records.begin(), records.end());
    if (records.size() > maxRecords) {
        records.pop_back(); // Удаление наихудшей записи
    }
}

void PersonalRecord::displayRecords() const {
    std::cout << "Личные рекорды:\n";
    for (size_t i = 0; i < records.size(); ++i) {
        std::cout << i + 1 << ". " << records[i] << " секунд" << std::endl;
    }
}