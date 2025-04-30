#include <stdio.h>
#include "../integral.h"
#include "test_integral.h"

int main(void){

    char *sep = "\n-----------------------------------\n\n";
    double i, eps = 0.001;

    printf("Test #1\n");
    printf("f(x) = 1\n");
    printf("Interval: [0, 2]\n");
    printf("eps = %lf\n", eps);
    printf("Integral value:      2\n");
    i = integral(&f1, 0, 2, eps);
    printf("Calculated integral: %.5lf\n", i);
    if (2. - eps < i && i < 2. + eps) printf("Correct " "\x1b[32m""\n" "\x1b[0m");
    else printf("Wrong " "\x1b[31m" "\n" "\x1b[0m");

    printf(sep);

    printf("Test #2\n");
    printf("f(x) = 2x\n");
    printf("Interval: [-1, 2]\n");
    printf("eps = %lf\n", eps);
    printf("Integral value:      3\n");
    i = integral(&f2, -1, 2, eps);
    printf("Calculated integral: %.5lf\n", i);
    if (3. - eps < i && i < 3. + eps) printf("Correct " "\x1b[32m""\n" "\x1b[0m");
    else printf("Wrong " "\x1b[31m" "\n" "\x1b[0m");

    printf(sep);

    printf("Test #3\n");
    printf("f(x) = x^2 - 3x + 5\n");
    printf("Interval: [-1, 2]\n");
    printf("eps = %lf\n", eps);
    printf("Integral value:      13.5\n");
    i = integral(&f3, -1, 2, eps);
    printf("Calculated integral: %.5lf\n", i);
    if (13.5 - eps < i && i < 13.5 + eps) printf("Correct " "\x1b[32m""\n" "\x1b[0m");
    else printf("Wrong " "\x1b[31m" "\n" "\x1b[0m");

    printf(sep);

    printf("Test #4\n");
    printf("f(x) = e^x\n");
    printf("Interval: [-1, 2]\n");
    printf("eps = %lf\n", eps);
    printf("Integral value:      7.02117\n");
    i = integral(&f4, -1, 2, eps);
    printf("Calculated integral: %.5lf\n", i);
    if (7.02117 - eps < i && i < 7.02117 + eps) printf("Correct " "\x1b[32m""\n" "\x1b[0m");
    else printf("Wrong " "\x1b[31m" "\n" "\x1b[0m");

    printf(sep);

    printf("Test #5\n");
    printf("f(x) = e^x + x^2 - 5\n");
    printf("Interval: [-1, 2]\n");
    printf("eps = %lf\n", eps);
    printf("Integral value:      -1.97882\n");
    i = integral(&f5, -1, 2, eps);
    printf("Calculated integral: %.5lf\n", i);
    if (-1.97882 - eps < i && i < -1.97882 + eps) printf("Correct " "\x1b[32m""\n" "\x1b[0m");
    else printf("Wrong " "\x1b[31m" "\n" "\x1b[0m");

    return 0;
}