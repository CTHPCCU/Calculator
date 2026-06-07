#include "Divide.h"
#include <stdexcept>
double Divide::calculate(double a, double b) const {
    //除數不為零
    if (b == 0) throw std::invalid_argument("Error: Division by zero.");
    return a / b;
}