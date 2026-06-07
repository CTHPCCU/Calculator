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
    std::stack<double> numStack;
    std::stack<char> opStack;
    numStack.push(nums[0]);

    for (size_t i = 0; i < ops.size(); i++)
    {
        char curOp = ops[i];
        while (!opStack.empty() && priority(opStack.top()) >= priority(curOp))
        {
            double b = numStack.top();
            numStack.pop();
            double a = numStack.top();
            numStack.pop();
            char op = opStack.top();
            opStack.pop();
            double r = 0;
            switch (op)
            {
            case '+':
                r = calc.computeSilent(add, a, b);
                break;
            case '-':
                r = calc.computeSilent(sub, a, b);
                break;
            case '*':
                r = calc.computeSilent(mul, a, b);
                break;
            case '/':
                r = calc.computeSilent(div, a, b);
                break;
            default:
                throw std::runtime_error("未知運算子");
            }
            numStack.push(r);
        }
        opStack.push(curOp);
        numStack.push(nums[i + 1]);
    }

    while (!opStack.empty())
    {
        double b = numStack.top();
        numStack.pop();
        double a = numStack.top();
        numStack.pop();
        char op = opStack.top();
        opStack.pop();
        double r = 0;
        switch (op)
        {
        case '+':
            r = calc.computeSilent(add, a, b);
            break;
        case '-':
            r = calc.computeSilent(sub, a, b);
            break;
        case '*':
            r = calc.computeSilent(mul, a, b);
            break;
        case '/':
            r = calc.computeSilent(div, a, b);
            break;
        default:
            throw std::runtime_error("未知運算子");
        }
        numStack.push(r);
    }

    double finalResult = numStack.top();
    // 只在這裡記錄一次最終結果
    calc.getResult().setValue(finalResult); 
    return finalResult;
}