#pragma once
#include <string>
#include <vector>

class InputParser
{
public:
    InputParser(const std::string &input);

    bool isValid() const;
    bool isSingle() const;    // 是否為單運算元（s, r 開頭）
    char getSingleOp() const; // 's' 或 'r'
    double getSingleNum() const;

    const std::vector<double> &getNums() const;
    const std::vector<char> &getOps() const;

private:
    bool valid;
    bool single;
    char singleOp;
    double singleNum;
    std::vector<double> nums;
    std::vector<char> ops;

    void parse(const std::string &input);
    void parseExpression(const std::string &input);
};