#pragma once
#include <math.h>

double f1(double x){
    return exp(x) - 3;
}

double f1_der(double x){
    return exp(x);
}

double g1(double x){
    return -x * x - x + 5;
}

double g1_der(double x){
    return -2 * x - 1;
}

double f2(double x){
    return 1 / (x + 3) + 3;
}

double f2_der(double x){
    return -1 / ((x + 3) * (x + 3));
}

double g2(double x){
    return powf(2, x) - 2;
}

double g2_der(double x){
    return powf(2, x) * logf(2);
}

double f3(double x){
    return x*x*x + x*x - 2 * x + 4;
}

double f3_der(double x){
    return 3 * x*x  + 2 * x - 2;
}

double g3(double x){
    return 1 / (x - 0.5);
}

double g3_der(double x){
    return -1 / ((x - 0.5) * (x - 0.5));
}

double f4(double x){
    return sqrt(x + 4);
}

double f4_der(double x){
    return 1 / (2 * sqrt(x + 4));
}

double g4(double x){
    return x*x - 3;
}

double g4_der(double x){
    return 2 * x;
}