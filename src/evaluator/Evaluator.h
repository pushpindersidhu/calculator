//
// Created by Pushpinder Sidhu on 2023-12-22.
//

#ifndef CALCULATOR_EVALUATOR_H
#define CALCULATOR_EVALUATOR_H


#include <string>

class Evaluator {
public:
    static double eval(const std::string &expression);

private:
    static int precedence(char c);
    static double operate(double operand1, double operand2, char op);
};


#endif //CALCULATOR_EVALUATOR_H
