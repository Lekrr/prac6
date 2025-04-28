#include <stdio.h>
#include "../integral.h"
#include "test_integral.h"

int main(void){

    char *sep = "\n-----------------------------------\n\n";

    printf("Test #1\n");
    printf("f(x) = 1\n");
    printf("Interval: [0, 2]\n");
    printf("eps = 0.001\n");
    printf("Integral value:      2\n");
    printf("Calculated integral: %.5lf\n", integral(&f1, 0, 2, 0.001));

    printf(sep);

    printf("Test #2\n");
    printf("f(x) = 2x\n");
    printf("Interval: [-1, 2]\n");
    printf("eps = 0.001\n");
    printf("Integral value:      3\n");
    printf("Calculated integral: %.5lf\n", integral(&f2, -1, 2, 0.001));

    printf(sep);

    printf("Test #3\n");
    printf("f(x) = x^2 - 3x + 5\n");
    printf("Interval: [-1, 2]\n");
    printf("eps = 0.001\n");
    printf("Integral value:      13.5\n");
    printf("Calculated integral: %.5lf\n", integral(&f3, -1, 2, 0.001));

    printf(sep);

    printf("Test #4\n");
    printf("f(x) = e^x\n");
    printf("Interval: [-1, 2]\n");
    printf("eps = 0.001\n");
    printf("Integral value:      7.02117\n");
    printf("Calculated integral: %.5lf\n", integral(&f4, -1, 2, 0.001));

    printf(sep);

    printf("Test #5\n");
    printf("f(x) = e^x + x^2 - 5\n");
    printf("Interval: [-1, 2]\n");
    printf("eps = 0.001\n");
    printf("Integral value:      -1.97882\n");
    printf("Calculated integral: %.5lf\n", integral(&f5, -1, 2, 0.001));

    return 0;
}