#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <stack>
#include <stdexcept>

enum operators
{
    PLUS = 1,
    MINUS,
    MULT,
    DIV
};

void calculateRNP(const std::string &input);