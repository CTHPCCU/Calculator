#include "Calculator.h"
#include "Add.h"
#include "Subtract.h"
#include "Multiply.h"
#include "Divide.h"
#include "Square.h"
#include "SquareRoot.h"
#include <iostream>

int main() {
    Calculator calc;

    Add add;
    Subtract sub;
    Multiply mul;
    Divide div;
    Square sq;
    SquareRoot sqRt;

    std::cout << calc.compute(add,  10, 3)  << "\n";  // 13
    std::cout << calc.compute(sub,  10, 3)  << "\n";  // 7
    std::cout << calc.compute(mul,  10, 3)  << "\n";  // 30
    std::cout << calc.compute(div,  10, 2)  << "\n";  // 5
    std::cout << calc.compute(sq,   4)      << "\n";  // 16
    std::cout << calc.compute(sqRt, 16)     << "\n";  // 4

    calc.printHistory();

    return 0;
}