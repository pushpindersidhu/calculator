//
// Created by Pushpinder Sidhu on 2023-12-20.
//

#ifndef Calculator_MATH_H
#define Calculator_MATH_H

namespace Math {
    extern const double PI;
    extern const double E;

    int add(int a, int b);
    int subtract(int a, int b);
    int multiply(int a, int b);
    int divide(int a, int b);

    double sine(double a);
    double cosine(double a);
    double tangent(double a);
    double cotangent(double a);
    double secant(double a);
    double cosecant(double a);

    double naturalLog(double a);
    double logBase10(double a);
    double logBaseN(double a, double n);

    double exponent(double a);
    double exponentBaseN(double a, double n);

    double squareRoot(double a);
    double cubeRoot(double a);
    double nthRoot(double a, double n);
    double factorial(int a);
    double absoluteValue(double a);
    double power(double a, double b);
    double inverse(double a);
    double percent(double a, double b);
    double radians(double a);
};


#endif //Calculator_MATH_H
