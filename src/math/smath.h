//
// Created by Pushpinder Sidhu on 2023-12-20.
//

#ifndef Calculator_MATH_H
#define Calculator_MATH_H


class Math {
public:
    static const double PI;
    static const double E;

    static int add(int a, int b);
    static int subtract(int a, int b);
    static int multiply(int a, int b);
    static int divide(int a, int b);

    static double sine(double a);
    static double cosine(double a);
    static double tangent(double a);
    static double cotangent(double a);
    static double secant(double a);
    static double cosecant(double a);

    static double naturalLog(double a);
    static double logBase10(double a);
    static double logBaseN(double a, double n);

    static double exponent(double a);
    static double exponentBaseN(double a, double n);

    static double squareRoot(double a);
    static double cubeRoot(double a);
    static double nthRoot(double a, double n);
    static double factorial(int a);
    static double absoluteValue(double a);
    static double power(double a, double b);
    static double inverse(double a);
    static double percent(double a, double b);
    static double radians(double a);
};


#endif //Calculator_MATH_H
