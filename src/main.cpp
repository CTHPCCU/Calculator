#include "Calculator.h"
#include "Operations/Square.h"
#include "Operations/SquareRoot.h"
#include "InputParser.h"
#include "ExprEvaluator.h"
#include <iostream>
#include <string>

int main()
{
    Calculator calc;
    ExprEvaluator evaluator(calc);

    Square sq;
    SquareRoot sqRt;

    std::string input;

    std::cout << "=== 計算機 ===\n";
    std::cout << "格式: 3+6 / 2+3*4 / s9(平方) / r16(開根號) / q(離開)\n\n";

    while (true)
    {
        std::cout << "> ";
        std::cin >> input;

        if (input == "q")
            break;

        InputParser parser(input);

        if (!parser.isValid())
        {
            std::cout << "格式錯誤，請輸入如 3+6 或 2+3*4\n";
            continue;
        }

        try
        {
            // 單運算元：s9 或 r16
            if (parser.isSingle())
            {
                double a = parser.getSingleNum();
                if (parser.getSingleOp() == 's')
                    std::cout << "結果: " << calc.compute(sq, a) << "\n";
                else
                    std::cout << "結果: " << calc.compute(sqRt, a) << "\n";
            }
            // 一般運算式：交給 ExprEvaluator 處理優先順序
            else
            {
                double result = evaluator.evaluate(
                    parser.getNums(),
                    parser.getOps());
                std::cout << "結果: " << result << "\n";
            }
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << "\n";
        }
    }

    calc.printHistory();
    return 0;
}