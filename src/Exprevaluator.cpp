#include "ExprEvaluator.h"
#include <stack>
#include <stdexcept>

ExprEvaluator::ExprEvaluator(Calculator &calc) : calc(calc) {}

int ExprEvaluator::priority(char op) const
{
    if (op == '*' || op == '/')
        return 2; // 高優先
    if (op == '+' || op == '-')
        return 1; // 低優先
    return 0;
}

double ExprEvaluator::evaluate(const std::vector<double> &nums,
                               const std::vector<char> &ops)
{
    // 兩個堆疊：一個放數字，一個放運算子
    std::stack<double> numStack;
    std::stack<char> opStack;

    // 先把第一個數字推進去
    numStack.push(nums[0]);

    for (size_t i = 0; i < ops.size(); i++)
    {
        char curOp = ops[i];

        // 如果目前運算子的優先級 <= 堆疊頂端的運算子
        // 就先把堆疊頂端的運算子算完，再推入目前的
        while (!opStack.empty() &&
               priority(opStack.top()) >= priority(curOp))
        {
            double b = numStack.top();
            numStack.pop();
            double a = numStack.top();
            numStack.pop();
            char op = opStack.top();
            opStack.pop();

            double result;
            switch (op)
            {
            case '+':
                result = calc.compute(add, a, b);
                break;
            case '-':
                result = calc.compute(sub, a, b);
                break;
            case '*':
                result = calc.compute(mul, a, b);
                break;
            case '/':
                result = calc.compute(div, a, b);
                break;
            default:
                throw std::runtime_error("未知運算子");
            }
            numStack.push(result);
        }

        opStack.push(curOp);
        numStack.push(nums[i + 1]);
    }

    // 把堆疊裡剩下的全部算完
    while (!opStack.empty())
    {
        double b = numStack.top();
        numStack.pop();
        double a = numStack.top();
        numStack.pop();
        char op = opStack.top();
        opStack.pop();

        double result;
        switch (op)
        {
        case '+':
            result = calc.compute(add, a, b);
            break;
        case '-':
            result = calc.compute(sub, a, b);
            break;
        case '*':
            result = calc.compute(mul, a, b);
            break;
        case '/':
            result = calc.compute(div, a, b);
            break;
        default:
            throw std::runtime_error("未知運算子");
        }
        numStack.push(result);
    }

    return numStack.top();
}