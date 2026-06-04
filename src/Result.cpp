#include "Result.h"

Result::Result() : value(0) {}
Result::Result(double value) : value(value) {
    history.push_back(value);
}

void Result::setValue(double value) {
    this->value = value;
    history.push_back(value);   // 每次設值都記錄
}

double Result::getValue() const {
    return value;
}

const std::vector<double>& Result::getHistory() const {
    return history;
}

void Result::printHistory() const {
    std::cout << "=== Calculation History ===\n";
    if (history.empty()) {
        std::cout << "(no records)\n";
        return;
    }
    for (size_t i = 0; i < history.size(); ++i)
        std::cout << "[" << i + 1 << "] " << history[i] << "\n";
}

void Result::clearHistory() {
    history.clear();
}