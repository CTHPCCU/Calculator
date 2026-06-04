#pragma once
#include "Operation.h"
class Subtract : public Operation {
public:
    double calculate(double a, double b = 0) const override;
};