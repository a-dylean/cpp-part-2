#include "RPN.hpp"

int strToInt(const std::string &str)
{
    std::istringstream ss(str);
    int ret;
    ss >> ret;
    return ret;
}

int performOperation(int a, int b, int op)
{
    switch (op)
    {
    case 1:
        return a + b;
    case 2:
        return a - b;
    case 3:
        return a * b;
    case 4:
    {
        if (b == 0)
            throw std::invalid_argument("division by 0");
        return a / b;
    }
    default:
        throw std::invalid_argument("invalid operator");
    }
};

int isOperator(const std::string &token)
{
    if (token.size() == 1)
    {
        if (token == "+")
            return PLUS;
        if (token == "-")
            return MINUS;
        if (token == "/")
            return DIV;
        if (token == "*")
            return MULT;
    }
    return 0;
};

void inputCheck(const std::string &token)
{
    const std::string ops = "+-/*";
    if (token.size() == 1 && ops.find(token[0]) != std::string::npos)
    {
        return;
    }
    std::string::size_type start = 0;
    if (token.size() > 1 && token[0] == '-')
    {
        start = 1;
    }
    for (std::string::size_type i = start; i < token.size(); ++i)
    {
        if (!std::isdigit(static_cast<unsigned char>(token[i])))
        {
            throw std::invalid_argument("expression contains wrong char");
        }
    }
}

void calculateRNP(const std::string &input)
{
    std::stack<int> stack;
    std::stringstream ss(input);
    std::string token;
    try
    {
        while (ss >> token)
        {
            inputCheck(token);
            int op = isOperator(token);
            if (op)
            {
                if (stack.size() < 2)
                    throw std::invalid_argument("not enough operands");

                int a = stack.top();
                stack.pop();
                int b = stack.top();
                stack.pop();

                stack.push(performOperation(b, a, op));
            }
            else
            {
                stack.push(strToInt(token));
            }
        }
        if (stack.size() != 1)
            throw std::invalid_argument("too many operands");
        std::cout << stack.top() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    ss.clear();
};