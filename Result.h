#pragma once
#include <vector>
#include <iostream>

class Result {
private:
    double value;
    std::vector<double> history;

public:
    Result();
    explicit Result(double value);

    void setValue(double value);   // 設定並自動加入歷史
    double getValue() const;

    const std::vector<double>& getHistory() const;
    void printHistory() const;
    void clearHistory();
};