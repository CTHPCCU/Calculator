#include "InputParser.h"
#include "Operations/Square.h"
#include "Operations/SquareRoot.h"
#include <cctype>
#include <stdexcept>

InputParser::InputParser(const std::string &input)
    : valid(false), single(false), singleOp(' '), singleNum(0)
{
    parse(input);
}

void InputParser::parse(const std::string &input)
{
    if (input.empty())
        return;

    // 純單運算元：s9 或 r16（整個輸入只有這個）
    if (input[0] == 's' || input[0] == 'r')
    {
        // 檢查後面是否還有運算子，有的話當運算式處理
        std::string rest = input.substr(1);
        bool hasOp = false;
        for (char c : rest)
            if (c == '+' || c == '-' || c == '*' || c == '/')
            {
                hasOp = true;
                break;
            }

        if (!hasOp)
        {
            try
            {
                singleNum = std::stod(rest);
                singleOp = input[0];
                single = true;
                valid = true;
            }
            catch (...)
            {
                valid = false;
            }
            return;
        }
    }

    parseExpression(input);
}

void InputParser::parseExpression(const std::string &input)
{
    Square sq;
    SquareRoot sqRt;
    size_t i = 0;

    while (i < input.size())
    {
        size_t j = i;

        // 處理 s 或 r 開頭的一元運算
        if (input[j] == 's' || input[j] == 'r')
        {
            char op = input[j];
            j++;
            size_t k = j;
            while (k < input.size() && (isdigit(input[k]) || input[k] == '.'))
                k++;
            if (k == j)
                return; // s or r 後面沒有數字，格式錯誤
            try
            {
                double n = std::stod(input.substr(j, k - j));
                double val = (op == 's') ? sq.calculate(n) : sqRt.calculate(n);
                nums.push_back(val);
            }
            catch (...)
            {
                return;
            }
            i = k;
        }
        else
        {
            // 一般數字（第一個允許負號）
            if (input[j] == '-' && nums.empty())
                j++;
            while (j < input.size() && (isdigit(input[j]) || input[j] == '.'))
                j++;
            if (j == i)
                return;
            try
            {
                nums.push_back(std::stod(input.substr(i, j - i)));
            }
            catch (...)
            {
                return;
            }
            i = j;
        }

        if (i >= input.size())
            break;

        // 讀運算子
        char c = input[i];
        if (c != '+' && c != '-' && c != '*' && c != '/')
            return;
        ops.push_back(c);
        i++;
    }

    if (nums.size() == ops.size() + 1 && !nums.empty())
        valid = true;
}

bool InputParser::isValid() const { return valid; }
bool InputParser::isSingle() const { return single; }
char InputParser::getSingleOp() const { return singleOp; }
double InputParser::getSingleNum() const { return singleNum; }

const std::vector<double> &InputParser::getNums() const { return nums; }
const std::vector<char> &InputParser::getOps() const { return ops; }