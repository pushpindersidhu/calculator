//
// Created by Pushpinder Sidhu on 2023-12-22.
//

#include "Evaluator.h"
#include <stack>

double Evaluator::eval(const std::string &expression) {
    std::stack<double> operands;
    std::stack<char> operators;

    for (int i = 0; i < expression.length(); i++) {
        char ch = expression[i];

        if (ch != '(' && ch != ')' && ch != '+' && ch != '-' && ch != '*' && ch != '/' && ch != '^' && !isdigit(ch) &&
            ch != '.') {
            throw std::invalid_argument("Invalid Expression: " + expression);
        }

        if (ch == ' ') {
            continue;
        }

        if (ch == '(') {
            operators.push(ch);
            continue;
        }

        if (isdigit(ch)) {
            double num = 0;

            while (i < expression.length() && isdigit(expression[i])) {
                num = num * 10 + (expression[i] - '0');
                i++;
            }

            if (i < expression.length() && expression[i] == '.') {
                i++;
                int decimal = 1;

                while (i < expression.length() && isdigit(expression[i])) {
                    num = num * 10 + (expression[i] - '0');
                    decimal *= 10;
                    i++;
                }

                num /= decimal;
            }

            operands.push(num);
            i--;
            continue;
        }

        if (ch == ')') {
            while (!operators.empty() && operators.top() != '(') {
                double operand2 = operands.top();
                operands.pop();

                double operand1 = operands.top();
                operands.pop();

                char op = operators.top();
                operators.pop();

                operands.push(operate(operand1, operand2, op));
            }

            operators.pop();
            continue;
        }

        while (!operators.empty() && precedence(operators.top()) >= precedence(ch)) {
            double operand2 = operands.top();
            operands.pop();

            double operand1 = operands.top();
            operands.pop();

            char op = operators.top();
            operators.pop();

            operands.push(operate(operand1, operand2, op));
        }

        operators.push(ch);
    }

    while (!operators.empty()) {
        double operand2 = operands.top();
        operands.pop();

        double operand1 = operands.top();
        operands.pop();

        char op = operators.top();
        operators.pop();

        operands.push(operate(operand1, operand2, op));
    }

    return operands.top();
}

int Evaluator::precedence(char c) {
    switch (c) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;

        default:
            return 0;
    }
}

double Evaluator::operate(double operand1, double operand2, char op) {
    switch (op) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            return operand1 / operand2;
        case '^':
            return pow(operand1, operand2);
        default:
            return 0;
    }
}
