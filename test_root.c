#include <stdio.h>
#include <math.h>
#include "root.h"

static double f1(double x){
    return exp(x) - 3;
}

static double f1_der(double x){
    return exp(x);
}

static double g1(double x){
    return -x * x - x + 5;
}

static double g1_der(double x){
    return -2 * x - 1;
}

static double f2(double x){
    return 1 / (x + 3) + 3;
}

static double f2_der(double x){
    return -1 / ((x + 3) * (x + 3));
}

static double g2(double x){
    return powf(2, x) - 2;
}

static double g2_der(double x){
    return powf(2, x) * logf(2);
}

static double f3(double x){
    return x*x*x + x*x - 2 * x + 4;
}

static double f3_der(double x){
    return 3 * x*x  + 2 * x - 2;
}

static double g3(double x){
    return 1 / (x - 0.5);
}

static double g3_der(double x){
    return -1 / ((x - 0.5) * (x - 0.5));
}

static double f4(double x){
    return sqrt(x + 4);
}

static double f4_der(double x){
    return 1 / (2 * sqrt(x + 4));
}

static double g4(double x){
    return x*x - 3;
}

static double g4_der(double x){
    return 2 * x;
}

static double select_eps(void){
    double eps = 0.001;
    printf("Select epsilon: ");
    scanf("%lf", &eps);
    return eps;
}

int test_root(void){

    char *sep = "\n-----------------------------------\n\n";
    double x, eps = select_eps();

    printf("Test #1\n");
    printf("f(x) = e^x - 3\ng(x) = -x^2 - x + 5\neps = %lf\n", eps);
    printf("Interval: [0, 2]\n");
    printf("Correct abscissas:    1.47239\n");
    x = root(&f1, &f1_der, &g1, &g1_der, 0, 2, eps);
    printf("Calculated abscissas: %.5lf\n", x);
    if (1.47239 - eps < x && x < 1.47239 + eps) printf("Correct " "\x1b[32m" "\n" "\x1b[0m");
    else printf("Wrong " "\x1b[31m" "\n" "\x1b[0m");

    printf(sep);

    printf("Test #2\n");
    printf("f(x) = 1/(x + 3) + 3\ng(x) = 2^x - 2\neps = %lf\n", eps);
    printf("Interval: [0, 4]\n");
    printf("Correct abscissas:    2.37464\n");
    x = root(&f2, &f2_der, &g2, &g2_der, 0, 4, eps);
    printf("Calculated abscissas: %.5lf\n", x);
    if (2.37464 - eps < x && x < 2.37464 + eps) printf("Correct " "\x1b[32m" "\n" "\x1b[0m");
    else printf("Wrong " "\x1b[31m" "\n" "\x1b[0m");

    printf(sep);

    printf("Test #3\n");
    printf("f(x) = x^3 + x^2 - 2x + 4\ng(x) = 1/(x - 0.5)\neps = %lf\n", eps);
    printf("Interval: [-4, -2]\n");
    printf("Correct abscissas:    -2.49648\n");
    x = root(&f3, &f3_der, &g3, &g3_der, -4, -2, eps);
    printf("Calculated abscissas: %.5lf\n", x);
    if (-2.49648 - eps < x && x < -2.49648 + eps) printf("Correct " "\x1b[32m" "\n" "\x1b[0m");
    else printf("Wrong " "\x1b[31m" "\n" "\x1b[0m");

    printf(sep);

    printf("Test #4\n");
    printf("f(x) = sqrt(x + 4)\ng(x) = x^2 - 3\neps = %lf\n", eps);
    printf("Interval: [2, 4]\n");
    printf("Correct abscissas:    2.34943\n");
    x = root(&f4, &f4_der, &g4, &g4_der, 2, 4, eps);
    printf("Calculated abscissas: %.5lf\n", x);
    if (2.34943 - eps < x && x < 2.34943 + eps) printf("Correct " "\x1b[32m" "\n" "\x1b[0m");
    else printf("Wrong " "\x1b[31m" "\n" "\x1b[0m");

    return 0;
}