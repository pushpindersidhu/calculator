//
// Created by Pushpinder Sidhu on 2023-12-21.
//

#include <iostream>
#include <iomanip>
#include "Menu.h"
#include "Option.h"
#include "../utils/colors.h"
#include "../math/smath.h"

using namespace std;

const Option options[] = {
        Option(1, "Add", "Add two numbers", Menu::Type::BASIC),
        Option(2, "Subtract", "Subtract two numbers", Menu::Type::BASIC),
        Option(3, "Multiply", "Multiply two numbers", Menu::Type::BASIC),
        Option(4, "Divide", "Divide two numbers", Menu::Type::BASIC),
        Option(5, "Sine", "Find the sine of a number", Menu::Type::SCIENTIFIC),
        Option(6, "Cosine", "Find the cosine of a number", Menu::Type::SCIENTIFIC),
        Option(7, "Tangent", "Find the tangent of a number", Menu::Type::SCIENTIFIC),
        Option(8, "Cotangent", "Find the cotangent of a number", Menu::Type::SCIENTIFIC),
        Option(9, "Secant", "Find the secant of a number", Menu::Type::SCIENTIFIC),
        Option(10, "Cosecant", "Find the cosecant of a number", Menu::Type::SCIENTIFIC),
        Option(11, "Natural Log", "Find the natural log of a number", Menu::Type::SCIENTIFIC),
        Option(12, "Log Base 10", "Find the log base 10 of a number", Menu::Type::SCIENTIFIC),
        Option(13, "Log Base N", "Find the log base N of a number", Menu::Type::SCIENTIFIC),
        Option(14, "Exponent", "Find the exponent of a number", Menu::Type::SCIENTIFIC),
        Option(15, "Exponent Base N", "Find the exponent base N of a number", Menu::Type::SCIENTIFIC),
        Option(16, "Square Root", "Find the square root of a number", Menu::Type::SCIENTIFIC),
        Option(17, "Cube Root", "Find the cube root of a number", Menu::Type::SCIENTIFIC),
        Option(18, "Nth Root", "Find the nth root of a number", Menu::Type::SCIENTIFIC),
        Option(19, "Factorial", "Find the factorial of a number", Menu::Type::SCIENTIFIC),
        Option(20, "Absolute Value", "Find the absolute value of a number", Menu::Type::SCIENTIFIC),
        Option(21, "Power", "Find the power of a number", Menu::Type::SCIENTIFIC),
        Option(22, "Inverse", "Find the inverse of a number", Menu::Type::SCIENTIFIC),
        Option(23, "Percent", "Find the percent of a number", Menu::Type::SCIENTIFIC),
        Option(24, "Radians", "Find the radians of a number", Menu::Type::SCIENTIFIC),
};

namespace Menu {
    Menu::Menu(Type type) : _type(type) {}

    void Menu::mainloop() {
        string result;

        while (true) {
            clearScreen();
            displayMenu();
            if (!result.empty()) {
                results += Cyan">>> ";
                results += BoldGreen"" + result + "\n";
                cout << results << endl;
            }
            prompt();

            int option = getOption();

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            switch (option) {
                case -1: {
                    cout << Red"\nExiting..." << endl;
                    return;
                }
                case 0: {
                    if (_type == Type::BASIC) {
                        setType(Type::SCIENTIFIC);
                    } else {
                        setType(Type::BASIC);
                    }

                    string mode = _type == Type::BASIC ? "Basic" : "Scientific";
                    result = "Switched to " + mode + " mode.";
                    break;
                }
                case 1: {
                    int a, b;
                    cout << "Enter two numbers: ";
                    cin >> a >> b;
                    result = "Add: " + to_string(a) + " + " + to_string(b) + " = " + to_string(Math::add(a, b));
                    break;
                }
                case 2: {
                    int a, b;
                    cout << "Enter two numbers: ";
                    cin >> a >> b;
                    result = "Subtract: " + to_string(a) + " - " + to_string(b) + " = " +
                             to_string(Math::subtract(a, b));
                    break;
                }
                case 3: {
                    int a, b;
                    cout << "Enter two numbers: ";
                    cin >> a >> b;
                    cout << "Multiply: " << a << " * " << b << " = " << Math::multiply(a, b) << endl;
                    result = "Multiply: " + to_string(a) + " * " + to_string(b) + " = " +
                             to_string(Math::multiply(a, b));
                    break;
                }
                case 4: {
                    int a, b;
                    cout << "Enter two numbers: ";
                    cin >> a >> b;
                    cout << "Divide: " << a << " / " << b << " = " << Math::divide(a, b) << endl;
                    result = "Divide: " + to_string(a) + " / " + to_string(b) + " = " + to_string(Math::divide(a, b));
                    break;
                }
                case 5: {
                    double a;
                    cout << "Enter a number: ";
                    cin >> a;
                    cout << "Sine: " << a << " = " << Math::sine(a) << endl;
                    result = "Sine: " + to_string(a) + " = " + to_string(Math::sine(a));
                    break;
                }
                case 6: {
                    double a;
                    cout << "Enter a number: ";
                    cin >> a;
                    cout << "Cosine: " << a << " = " << Math::cosine(a) << endl;
                    result = "Cosine: " + to_string(a) + " = " + to_string(Math::cosine(a));
                    break;
                }
                case 7: {
                    double a;
                    cout << "Enter a number: ";
                    cin >> a;
                    cout << "Tangent: " << a << " = " << Math::tangent(a) << endl;
                    result = "Tangent: " + to_string(a) + " = " + to_string(Math::tangent(a));
                    break;
                }
                case 8: {
                    double a;
                    cout << "Enter a number: ";
                    cin >> a;
                    cout << "Cotangent: " << a << " = " << Math::cotangent(a) << endl;
                    result = "Cotangent: " + to_string(a) + " = " + to_string(Math::cotangent(a));
                    break;
                }
                case 9: {
                    double a;
                    cout << "Enter a number: ";
                    cin >> a;
                    cout << "Secant: " << a << " = " << Math::secant(a) << endl;
                    result = "Secant: " + to_string(a) + " = " + to_string(Math::secant(a));
                    break;
                }
                case 10: {
                    double a;
                    cout << "Enter a number: ";
                    cin >> a;
                    cout << "Cosecant: " << a << " = " << Math::cosecant(a) << endl;
                    result = "Cosecant: " + to_string(a) + " = " + to_string(Math::cosecant(a));
                    break;
                }
                case 11: {
                    double a;
                    cout << "Enter a number:";
                    cin >> a;
                    cout << "Natural Log: " << a << " = " << Math::naturalLog(a) << endl;
                    result = "Natural Log: " + to_string(a) + " = " + to_string(Math::naturalLog(a));
                    break;
                }
                case 12: {
                    double a;
                    cout << "Enter a number: ";
                    cin >> a;
                    cout << "Log Base 10: " << a << " = " << Math::logBase10(a) << endl;
                    result = "Log Base 10: " + to_string(a) + " = " + to_string(Math::logBase10(a));
                    break;
                }
                case 13: {
                    double a, n;
                    cout << "Enter a number: ";
                    cin >> a;
                    cout << "Enter the base: ";
                    cin >> n;
                    cout << "Log Base N: " << a << " log " << n << " = " << Math::logBaseN(a, n) << endl;
                    result = "Log Base N: " + to_string(a) + " log " + to_string(n) + " = " +
                             to_string(Math::logBaseN(a, n));
                    break;
                }
                case 14: {
                    double a;
                    cout << "Enter a number: ";
                    cin >> a;
                    cout << "Exponent: " << "e^" << a << " = " << Math::exponent(a) << endl;
                    result = "Exponent: " + to_string(a) + " = " + to_string(Math::exponent(a));
                    break;
                }
                case 15: {
                    double a, n;
                    cout << "Enter a number: ";
                    cin >> a;
                    cout << "Enter the base: ";
                    cin >> n;
                    cout << "Exponent Base N: " << n << "^" << a << " = " << Math::exponentBaseN(a, n) << endl;
                    result = "Exponent Base N: " + to_string(a) + " = " + to_string(Math::exponentBaseN(a, n));
                    break;
                }
                case 16: {
                    double a;
                    cout << "Enter a number: ";
                    cin >> a;
                    cout << "Square Root: " << "√" << a << " = " << Math::squareRoot(a) << endl;
                    result = "Square Root: " + to_string(a) + " = " + to_string(Math::squareRoot(a));
                    break;
                }
                case 17: {
                    double a;
                    cout << "Enter a number: ";
                    cin >> a;
                    cout << "Cube Root: " << "∛" << a << " = " << Math::cubeRoot(a) << endl;
                    result = "Cube Root: " + to_string(a) + " = " + to_string(Math::cubeRoot(a));
                    break;
                }
                case 18: {
                    double a, n;
                    cout << "Enter a number: ";
                    cin >> a;
                    cout << "Enter the base: ";
                    cin >> n;
                    cout << "Nth Root: " << n << "√" << a << " = " << Math::nthRoot(a, n) << endl;
                    result = "Nth Root: " + to_string(a) + " = " + to_string(Math::nthRoot(a, n));
                    break;
                }
                case 19: {
                    int a;
                    cout << "Enter a number: ";
                    cin >> a;
                    cout << "Factorial: " << a << "! = " << Math::factorial(a) << endl;
                    result = "Factorial: " + to_string(a) + " = " + to_string(Math::factorial(a));
                    break;
                }
                case 20: {
                    double a;
                    cout << "Enter a number: ";
                    cin >> a;
                    cout << "Absolute Value: " << "|" << a << "| = " << Math::absoluteValue(a) << endl;
                    result = "Absolute Value: " + to_string(a) + " = " + to_string(Math::absoluteValue(a));
                    break;
                }
                case 21: {
                    double a, b;
                    cout << "Enter a number: ";
                    cin >> a;
                    cout << "Enter the power: ";
                    cin >> b;
                    cout << "Power: " << a << "^" << b << " = " << Math::power(a, b) << endl;
                    result = "Power: " + to_string(a) + " = " + to_string(Math::power(a, b));
                    break;
                }
                case 22: {
                    double a;
                    cout << "Enter a number: ";
                    cin >> a;
                    cout << "Inverse: " << "1/" << a << " = " << Math::inverse(a) << endl;
                    result = "Inverse: " + to_string(a) + " = " + to_string(Math::inverse(a));
                    break;
                }
                case 23: {
                    double a, b;
                    cout << "Enter a number: ";
                    cin >> a;
                    cout << "Enter the percent: ";
                    cin >> b;
                    cout << "Percent: " << a << "%" << b << " = " << Math::percent(a, b) << endl;
                    result = "Percent: " + to_string(a) + " = " + to_string(Math::percent(a, b));
                    break;
                }
                case 24: {
                    double a;
                    cout << "Enter a number: ";
                    cin >> a;
                    cout << "Radians: " << a << " = " << Math::radians(a) << endl;
                    result = "Radians: " + to_string(a) + " = " + to_string(Math::radians(a));
                    break;
                }
                default: {
                    // red
                    result = "\033[1;31mInvalid option: " + to_string(option) + "\033[0m";
                    break;
                }
            }
        }
    }

    Type Menu::getType() const {
        return _type;
    }

    void Menu::setType(Type type) {
        Menu::_type = type;
    }

    void Menu::clearScreen() {
        cout << "\033[2J\033[1;1H";
    }

    void Menu::displayMenu() {
        displayMenuHeader();

        int lastId = 0;
        for (const auto &option: options) {
            if (option.type == _type || option.type == Type::BASIC) {
                if (option.id % 3 == 1 or option.id == 0) {
                    cout << setw(1) << left << Cyan << "|" << Reset;
                }
                cout << setw(4) << right << option.id << ". " << setw(20) << left << option.name;
                if (option.id % 3 == 0) {
                    cout << setw(5) << right << Cyan << "|" << Reset;
                    cout << endl;
                }
                lastId = option.id;
            }
        }
        if (lastId % 3 != 0) {
            cout << setfill(' ') << setw(30 * (3 - (lastId % 3)) - 2) << right << Cyan"|";
            cout << endl;
        }
        cout << Cyan << setfill('-') << setw(80) << "-" << Reset << endl;
    }

    void Menu::displayMenuHeader() {
        cout << Cyan << setfill('-') << setw(80) << "-" << Reset << endl;
        cout << Cyan << setfill(' ') << setw(31) << left << "|" << Reset;
        cout << Green << "Calculator - Sidhu" << Reset;
        cout << Cyan << setw(31) << right << "|" << Reset << endl;

        cout << Cyan << setw(3) << left << "|" << Reset;
        cout << setw(41) << left << Red"-1. Exit";

        const string mode = _type == Type::BASIC ? "Scientific" : "Basic";
        cout << setw(40) << right << Yellow"0. " + mode + " mode";

        cout << setw(10) << right << Cyan << "|" << Reset;
        cout << endl;

        cout << Cyan << setfill('-') << setw(80) << "-" << Reset << endl;
        cout << setfill(' ');
    }

    void Menu::prompt() {
        cout << Cyan"Please enter your choice: ";
    }

    int Menu::getOption() {
        int option;
        cin >> option;
        return option;
    }
} // Menu