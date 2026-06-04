#include "Calculator.h"
#include "Add.h"
#include "Subtract.h"
#include "Multiply.h"
#include "Divide.h"
#include "Square.h"
#include "SquareRoot.h"
#include <iostream>
#include <string>
#include <sstream>

int main() {
    Calculator calc;

    Add add;
    Subtract sub;
    Multiply mul;
    Divide div;
    Square sq;
    SquareRoot sqRt;

    std::string input;

    std::cout << "=== 計算機 ===\n";
    std::cout << "格式: 3+6 / 10-2 / 4*5 / 8/2 / s9(平方) / r16(開根號) / q(離開)\n\n";

    while (true) {
        std::cout << "> ";
        std::cin >> input;

        if (input == "q") break;

        try {
            // 平方：s9
            if (input[0] == 's') {
                double a = std::stod(input.substr(1));
                std::cout << "結果: " << calc.compute(sq, a) << "\n";
            }
            // 開根號：r16
            else if (input[0] == 'r') {
                double a = std::stod(input.substr(1));
                std::cout << "結果: " << calc.compute(sqRt, a) << "\n";
            }
            // 一般運算：3+6
            else {
                // 找運算子位置（從第1個字元開始，避免負號開頭）
                size_t pos = std::string::npos;
                for (size_t i = 1; i < input.size(); i++) {
                    char c = input[i];
                    if (c == '+' || c == '-' || c == '*' || c == '/') {
                        pos = i;
                        break;
                    }
                }

                if (pos == std::string::npos) {
                    std::cout << "格式錯誤，請輸入如 3+6\n";
                    continue;
                }

                double a = std::stod(input.substr(0, pos));
                char op  = input[pos];
                double b = std::stod(input.substr(pos + 1));

                if      (op == '+') std::cout << "結果: " << calc.compute(add, a, b) << "\n";
                else if (op == '-') std::cout << "結果: " << calc.compute(sub, a, b) << "\n";
                else if (op == '*') std::cout << "結果: " << calc.compute(mul, a, b) << "\n";
                else if (op == '/') std::cout << "結果: " << calc.compute(div, a, b) << "\n";
            }
        } catch (std::exception& e) {
            std::cout << e.what() << "\n";
        }
    }

    calc.printHistory();
    return 0;
}