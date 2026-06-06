#include "SquareRoot.h"
#include <cmath>
#include <stdexcept>
double SquareRoot::calculate(double a, double b) const {
    if (a < 0) throw std::invalid_argument("Error: Cannot take square root of a negative number.");
    return std::sqrt(a);
}