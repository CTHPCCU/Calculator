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

    const std::vector<double>& getHistory() const; //回傳 const 參考，避免複製整個 vector，禁止外部修改歷史紀錄。
    void printHistory() const;
    void clearHistory();
};