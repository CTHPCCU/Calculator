#pragma once
class Operation {
public:
    virtual ~Operation() = default;
    virtual double calculate(double a, double b = 0) const = 0;
};