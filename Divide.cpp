#include "Divide.h"
#include <stdexcept>
double Divide::calculate(double a, double b) const {
    if (b == 0) throw std::invalid_argument("Error: Division by zero.");
    return a / b;
}