#pragma once
#include "Calculator.h"
#include "Operations/Add.h"
#include "Operations/Subtract.h"
#include "Operations/Multiply.h"
#include "Operations/Divide.h"
#include <vector>

class ExprEvaluator
{
public:
    ExprEvaluator(Calculator &calc);

    // 傳入 InputParser 解析好的 nums 和 ops，回傳最終結果
    double evaluate(const std::vector<double> &nums,
                    const std::vector<char> &ops);

private:
    Calculator &calc;
    Add add;
    Subtract sub;
    Multiply mul;
    Divide div;

    int priority(char op) const; // 回傳運算子優先級
};