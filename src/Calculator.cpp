#include "Calculator.h"

Calculator::Calculator() {}

double Calculator::compute(const Operation& op, double a, double b) {
    double val = op.calculate(a, b);
    result.setValue(val);
    return val;
}

double Calculator::compute(const Operation& op, double a) {
    double val = op.calculate(a);
    result.setValue(val);
    return val;
}

const Result& Calculator::getResult() const {
    return result;
}

void Calculator::printHistory() const {
    result.printHistory();
}

void Calculator::clearHistory() {
    result.clearHistory();
}