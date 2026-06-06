#pragma once
#include "Result.h"
#include "Operations/Operation.h"

class Calculator
{
private:
    Result result;

public:
    Calculator();

    // 雙運算元（加減乘除）
    double compute(const Operation &op, double a, double b);
    double computeSilent(const Operation &op, double a, double b);
    
    // 單運算元（平方、開根號）
    double compute(const Operation &op, double a);
    double computeSilent(const Operation &op, double a);

    const Result &getResult() const;
    Result& getResult();  // 非 const 版，供 ExprEvaluator 寫入最終結果
    void printHistory() const;
    void clearHistory();
};