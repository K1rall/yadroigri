#include "ErrorLog.h"
#include <iostream>

#include "ErrorLog.h"
#include <iostream>

ErrorLog::ErrorLog() {
    //  Конструктор по умолчанию
}

void ErrorLog::addError(const std::string& errorMessage) {
    errors.push_back(errorMessage);
}

void ErrorLog::showErrors() const {
    if (errors.empty()) {
        std::cout << "Ошибок нет." << std::endl;
    }
    else {
        std::cout << "Список ошибок:" << std::endl;
        for (size_t i = 0; i < errors.size(); ++i) {
            std::cout << i + 1 << ". " << errors[i] << std::endl;
        }
    }
}