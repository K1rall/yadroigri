#pragma once

#include <vector>
#include <string>

class ErrorLog {
private:
    std::vector<std::string> errors;

public:
    ErrorLog();
    void addError(const std::string& errorMessage);
    void showErrors() const;
};