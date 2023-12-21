//
// Created by Pushpinder Sidhu on 2023-12-20.
//

#include <cmath>
#include "smath.h"

const double Math::PI = M_PI;
const double Math::E = M_E;

int Math::add(int a, int b) {
    return a + b;
}

int Math::subtract(int a, int b) {
    return a - b;
}

int Math::multiply(int a, int b) {
    return a * b;
}

int Math::divide(int a, int b) {
    return a / b;
}

double Math::sine(double a) {
    return sin(a);
}

double Math::cosine(double a) {
    return cos(a);
}

double Math::tangent(double a) {
    return tan(a);
}

double Math::cotangent(double a) {
    return 1 / tan(a);
}

double Math::secant(double a) {
    return 1 / cos(a);
}

double Math::cosecant(double a) {
    return 1 / sin(a);
}

double Math::naturalLog(double a) {
    return log(a);
}

double Math::logBase10(double a) {
    return log10(a);
}

double Math::logBaseN(double a, double n) {
    return log(a) / log(n);
}

double Math::exponent(double a) {
    return exp(a);
}

double Math::exponentBaseN(double a, double n) {
    return pow(n, a);
}

double Math::squareRoot(double a) {
    return sqrt(a);
}

double Math::cubeRoot(double a) {
    return cbrt(a);
}

double Math::nthRoot(double a, double n) {
    return pow(a, 1 / n);
}

double Math::factorial(int a) {
    if (a < 0) {
        return -1;
    }

    for (int i = a - 1; i > 0; i--) {
        a *= i;
    }

    return a;
}

double Math::absoluteValue(double a) {
    return abs(a);
}

double Math::power(double a, double b) {
    return pow(a, b);
}

double Math::inverse(double a) {
    return 1 / a;
}

double Math::percent(double a, double b) {
    return (a / 100) * b;
}

double Math::radians(double a) {
    return a * (PI / 180);
}
