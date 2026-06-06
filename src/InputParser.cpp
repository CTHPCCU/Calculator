#include "InputParser.h"
#include <cctype>
#include <stdexcept>

InputParser::InputParser(const std::string& input)
    : valid(false), single(false), singleOp(' '), singleNum(0)
{
    parse(input);
}

void InputParser::parse(const std::string& input) {
    if (input.empty()) return;

    // 單運算元：s9（平方）或 r16（開根號）
    if (input[0] == 's' || input[0] == 'r') {
        try {
            singleNum = std::stod(input.substr(1));
            singleOp  = input[0];
            single    = true;
            valid     = true;
        } catch (...) {
            valid = false;
        }
        return;
    }

    // 一般運算式：3+6+9
    parseExpression(input);
}

void InputParser::parseExpression(const std::string& input) {
    size_t i = 0;

    while (i < input.size()) {
        // 讀一個數字
        size_t j = i;

        // 第一個數字允許負號開頭（例如 -3+6）
        if (j < input.size() && input[j] == '-' && nums.empty())
            j++;

        while (j < input.size() &&
               (isdigit(input[j]) || input[j] == '.'))
            j++;

        // j == i 代表沒讀到任何數字，格式錯誤
        if (j == i) return;

        try {
            nums.push_back(std::stod(input.substr(i, j - i)));
        } catch (...) {
            return;
        }

        i = j;
        if (i >= input.size()) break;

        // 讀一個運算子
        char c = input[i];
        if (c != '+' && c != '-' && c != '*' && c != '/') return;
        ops.push_back(c);
        i++;
    }

    // 數字比運算子多一個才合法，例如 [3,6,9] 配 [+,+]
    if (nums.size() == ops.size() + 1 && !nums.empty())
        valid = true;
}

bool   InputParser::isValid()      const { return valid;     }
bool   InputParser::isSingle()     const { return single;    }
char   InputParser::getSingleOp()  const { return singleOp;  }
double InputParser::getSingleNum() const { return singleNum; }

const std::vector<double>& InputParser::getNums() const { return nums; }
const std::vector<char>&   InputParser::getOps()  const { return ops;  }