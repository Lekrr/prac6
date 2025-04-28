#include <stdio.h>
#include <math.h>
#include "../root.h"
#include "test_root.h"

int main(void){

    char *sep = "\n-----------------------------------\n\n";

    printf("Test #1\n");
    printf("f(x) = e^x - 3\ng(x) = -x^2 - x + 5\neps = 0.001\n");
    printf("Interval: [0, 2]\n");
    printf("Correct abscissas:    1.47239\n");
    printf("Calculated abscissas: %.5lf\n", root(&f1, &f1_der, &g1, &g1_der, 0, 2, 0.001));

    printf(sep);

    printf("Test #2\n");
    printf("f(x) = 1/(x + 3) + 3\ng(x) = 2^x - 2\neps = 0.001\n");
    printf("Interval: [0, 4]\n");
    printf("Correct abscissas:    2.37464\n");
    printf("Calculated abscissas: %.5lf\n", root(&f2, &f2_der, &g2, &g2_der, 0, 4, 0.001));

    printf(sep);

    printf("Test #3\n");
    printf("f(x) = x^3 + x^2 - 2x + 4\ng(x) = 1/(x - 0.5)\neps = 0.001\n");
    printf("Interval: [-4, -2]\n");
    printf("Correct abscissas:    -2.49648\n");
    printf("Calculated abscissas: %.5lf\n", root(&f3, &f3_der, &g3, &g3_der, -4, -2, 0.001));

    printf(sep);

    printf("Test #4\n");
    printf("f(x) = sqrt(x + 4)\ng(x) = x^2 - 3\neps = 0.001\n");
    printf("Interval: [2, 4]\n");
    printf("Correct abscissas:    2.34943\n");
    printf("Calculated abscissas: %.5lf\n", root(&f4, &f4_der, &g4, &g4_der, 2, 4, 0.001));

    return 0;
}