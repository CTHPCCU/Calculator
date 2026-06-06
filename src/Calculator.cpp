#include "Calculator.h"

Calculator::Calculator() {}

double Calculator::compute(const Operation& op, double a, double b) {
    double val = op.calculate(a, b);
    result.setValue(val);
    return val;
}

double Calculator::computeSilent(const Operation& op, double a, double b) {
    return op.calculate(a, b);
}

double Calculator::compute(const Operation& op, double a) {
    double val = op.calculate(a);
    result.setValue(val);
    return val;
}

double Calculator::computeSilent(const Operation& op, double a) {
    return op.calculate(a);
}

const Result& Calculator::getResult() const {
    return result;
}

Result& Calculator::getResult() {
    return result;
}

void Calculator::printHistory() const {
    result.printHistory();
}

void Calculator::clearHistory() {
    result.clearHistory();
}