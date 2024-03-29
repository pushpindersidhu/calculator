//
// Created by Pushpinder Sidhu on 2023-12-21.
//

#include <iostream>
#include <iomanip>
#include <limits>
#include "Menu.h"
#include "Option.h"
#include "../evaluator/Evaluator.h"
#include "../utils/colors.h"
#include "../math/smath.h"

using namespace std;

const Option options[] = {
        Option(1, "Add", "Add two numbers", Menu::Type::BASIC),
        Option(2, "Subtract", "Subtract two numbers", Menu::Type::BASIC),
        Option(3, "Multiply", "Multiply two numbers", Menu::Type::BASIC),
        Option(4, "Divide", "Divide two numbers", Menu::Type::BASIC),
        Option(5, "Sine", "Sine of a number", Menu::Type::SCIENTIFIC),
        Option(6, "Cosine", "Cosine of a number", Menu::Type::SCIENTIFIC),
        Option(7, "Tangent", "Tangent of a number", Menu::Type::SCIENTIFIC),
        Option(8, "Cotangent", "Cotangent of a number", Menu::Type::SCIENTIFIC),
        Option(9, "Secant", "Secant of a number", Menu::Type::SCIENTIFIC),
        Option(10, "Cosecant", "Cosecant of a number", Menu::Type::SCIENTIFIC),
        Option(11, "Natural Log", "Natural Log of a number", Menu::Type::SCIENTIFIC),
        Option(12, "Log Base 10", "Log Base 10 of a number", Menu::Type::SCIENTIFIC),
        Option(13, "Log Base N", "Log Base N of a number", Menu::Type::SCIENTIFIC),
        Option(14, "Exponent", "Exponent of a number", Menu::Type::SCIENTIFIC),
        Option(15, "Exponent Base N", "Exponent Base N of a number", Menu::Type::SCIENTIFIC),
        Option(16, "Square Root", "Square Root of a number", Menu::Type::SCIENTIFIC),
        Option(17, "Cube Root", "Cube Root of a number", Menu::Type::SCIENTIFIC),
        Option(18, "Nth Root", "Nth Root of a number", Menu::Type::SCIENTIFIC),
        Option(19, "Factorial", "Factorial of a number", Menu::Type::SCIENTIFIC),
        Option(20, "Absolute Value", "Absolute Value of a number", Menu::Type::SCIENTIFIC),
        Option(21, "Power", "Power of a number", Menu::Type::SCIENTIFIC),
        Option(22, "Inverse", "Inverse of a number", Menu::Type::SCIENTIFIC),
        Option(23, "Percent", "Percent of a number", Menu::Type::SCIENTIFIC),
        Option(24, "Radians", "Radians of a number", Menu::Type::SCIENTIFIC),
        Option(25, "Evaluate", "Evaluate an expression", Menu::Type::SCIENTIFIC)
};

namespace Menu {
    Menu::Menu(Type type) : _type(type) {}

    Menu::Menu() {
        this->_type = Type::BASIC;
        cout << Green"Welcome to the calculator!" << endl << endl;

        cout << Reset"What mode would you like to use?" << endl;
        cout << "Note: You can switch modes at any time by entering 0." << endl;
        cout << "1. Basic" << endl;
        cout << "2. Scientific" << endl;
        cout << Cyan"Enter your choice: ";
        int option;
        cin >> option;

        while (cin.fail() or option != 1 and option != 2) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << Red"Invalid option!" << Cyan" Try Again: ";
            cin >> option;
        }

        setType(option == 1 ? Type::BASIC : Type::SCIENTIFIC);
    }

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

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            int option = getOption();

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if (getType() == Type::BASIC and option > 4) {
                result = Red"Invalid option: " + to_string(option);
                continue;
            }

            switch (option) {
                case -1: {
                    cout << Red"\nExiting..." << endl;
                    exit(0);
                }
                case 0: {
                    if (getType() == Type::BASIC) {
                        setType(Type::SCIENTIFIC);
                    } else {
                        setType(Type::BASIC);
                    }

                    string mode = getType() == Type::BASIC ? "Basic" : "Scientific";
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
                    result = "Multiply: " + to_string(a) + " * " + to_string(b) + " = " +
                             to_string(Math::multiply(a, b));
                    break;
                }
                case 4: {
                    int a, b;
                    cout << "Enter two numbers: ";
                    cin >> a >> b;
                    result = "Divide: " + to_string(a) + " / " + to_string(b) + " = " + to_string(Math::divide(a, b));
                    break;
                }
                case 5: {
                    double a;
                    cout << "Enter a number: ";
                    cin >> a;
                    result = "Sine: " + to_string(a) + " = " + to_string(Math::sine(a));
                    break;
                }
                case 6: {
                    double a;
                    cout << "Enter a number: ";
                    cin >> a;
                    result = "Cosine: " + to_string(a) + " = " + to_string(Math::cosine(a));
                    break;
                }
                case 7: {
                    double a;
                    cout << "Enter a number: ";
                    cin >> a;
                    result = "Tangent: " + to_string(a) + " = " + to_string(Math::tangent(a));
                    break;
                }
                case 8: {
                    double a;
                    cout << "Enter a number: ";
                    cin >> a;
                    result = "Cotangent: " + to_string(a) + " = " + to_string(Math::cotangent(a));
                    break;
                }
                case 9: {
                    double a;
                    cout << "Enter a number: ";
                    cin >> a;
                    result = "Secant: " + to_string(a) + " = " + to_string(Math::secant(a));
                    break;
                }
                case 10: {
                    double a;
                    cout << "Enter a number: ";
                    cin >> a;
                    result = "Cosecant: " + to_string(a) + " = " + to_string(Math::cosecant(a));
                    break;
                }
                case 11: {
                    double a;
                    cout << "Enter a number:";
                    cin >> a;
                    result = "Natural Log: " + to_string(a) + " = " + to_string(Math::naturalLog(a));
                    break;
                }
                case 12: {
                    double a;
                    cout << "Enter a number: ";
                    cin >> a;
                    result = "Log Base 10: " + to_string(a) + " = " + to_string(Math::logBase10(a));
                    break;
                }
                case 13: {
                    double a, n;
                    cout << "Enter a number: ";
                    cin >> a;
                    cout << "Enter the base: ";
                    cin >> n;
                    result = "Log Base N: " + to_string(a) + " log " + to_string(n) + " = " +
                             to_string(Math::logBaseN(a, n));
                    break;
                }
                case 14: {
                    double a;
                    cout << "Enter a number: ";
                    cin >> a;
                    result = "Exponent: " + to_string(a) + " = " + to_string(Math::exponent(a));
                    break;
                }
                case 15: {
                    double a, n;
                    cout << "Enter a number: ";
                    cin >> a;
                    cout << "Enter the base: ";
                    cin >> n;
                    result = "Exponent Base N: " + to_string(a) + " = " + to_string(Math::exponentBaseN(a, n));
                    break;
                }
                case 16: {
                    double a;
                    cout << "Enter a number: ";
                    cin >> a;
                    result = "Square Root: " + to_string(a) + " = " + to_string(Math::squareRoot(a));
                    break;
                }
                case 17: {
                    double a;
                    cout << "Enter a number: ";
                    cin >> a;
                    result = "Cube Root: " + to_string(a) + " = " + to_string(Math::cubeRoot(a));
                    break;
                }
                case 18: {
                    double a, n;
                    cout << "Enter a number: ";
                    cin >> a;
                    cout << "Enter the base: ";
                    cin >> n;
                    result = "Nth Root: " + to_string(a) + " = " + to_string(Math::nthRoot(a, n));
                    break;
                }
                case 19: {
                    int a;
                    cout << "Enter a number: ";
                    cin >> a;
                    result = "Factorial: " + to_string(a) + " = " + to_string(Math::factorial(a));
                    break;
                }
                case 20: {
                    double a;
                    cout << "Enter a number: ";
                    cin >> a;
                    result = "Absolute Value: " + to_string(a) + " = " + to_string(Math::absoluteValue(a));
                    break;
                }
                case 21: {
                    double a, b;
                    cout << "Enter a number: ";
                    cin >> a;
                    cout << "Enter the power: ";
                    cin >> b;
                    result = "Power: " + to_string(a) + " = " + to_string(Math::power(a, b));
                    break;
                }
                case 22: {
                    double a;
                    cout << "Enter a number: ";
                    cin >> a;
                    result = "Inverse: " + to_string(a) + " = " + to_string(Math::inverse(a));
                    break;
                }
                case 23: {
                    double a, b;
                    cout << "Enter a number: ";
                    cin >> a;
                    cout << "Enter the percent: ";
                    cin >> b;
                    result = "Percent: " + to_string(a) + " = " + to_string(Math::percent(a, b));
                    break;
                }
                case 24: {
                    double a;
                    cout << "Enter a number: ";
                    cin >> a;
                    result = "Radians: " + to_string(a) + " = " + to_string(Math::radians(a));
                    break;
                }
                case 25: {
                    string expression;
                    cout << "Enter an expression: ";
                    cin >> expression;
                    try {
                        result = "Evaluate: " + expression + " = " + to_string(Evaluator::eval(expression));
                    } catch (const exception &e) {
                        result = Red + string(e.what());
                    }
                    break;
                }
                default: {
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
            if (option.type == getType() || option.type == Type::BASIC) {
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

    void Menu::displayMenuHeader() const {
        cout << Cyan << setfill('-') << setw(80) << "-" << Reset << endl;
        cout << Cyan << setfill(' ') << setw(31) << left << "|" << Reset;
        cout << Green << "Calculator - Sidhu" << Reset;
        cout << Cyan << setw(31) << right << "|" << Reset << endl;

        cout << Cyan << setw(3) << left << "|" << Reset;
        cout << setw(41) << left << Red"-1. Exit";

        const string mode = getType() == Type::BASIC ? "Scientific" : "Basic";
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
