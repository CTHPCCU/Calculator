#include "SquareRoot.h"
#include <cmath>
#include <stdexcept>
double SquareRoot::calculate(double a, double b) const {
    //負數沒有實數平方根
    if (a < 0) throw std::invalid_argument("Error: Cannot take square root of a negative number.");
    return std::sqrt(a);
}