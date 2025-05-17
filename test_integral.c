#include <stdio.h>
#include <math.h>
#include "integral.h"

static double f1(double x){
    
    return 1;
}

static double f2(double x){
    return 2 * x;
}

static double f3(double x){
    return x * x - 3 * x + 5;
}

static double f4(double x){
    return exp(x);
}

static double f5(double x){
    return exp(x) + x * x - 4;
}

// provides prompt to seletc eps
static double select_eps(void){
    double eps = 0.001;
    printf("Select epsilon: ");
    scanf("%lf", &eps);
    return eps;
}

static void test(func_t f, double eps, double a, double b, unsigned n, char *f_str){
    printf("\nTest #%u\n", n);
    printf("f(x) = %s\n", f_str);
    printf("Interval: [%.2lf, %.2lf]\n", a, b);
    printf("eps = %lf\n", eps);
    double i = integral(f, a, b, eps);
    printf("Calculated integral: %.5lf\n", i);
}

int test_integral(void){

    printf("Testing integral function\n\n");

    double i, eps = select_eps();
    unsigned n = 1;

    printf("Run a premade set of tests (0) or run custom tests (1): ");
    unsigned test_type;
    scanf("%u", &test_type);
    if(test_type){
        func_t func_arr[] = {NULL, &f1, &f2, &f3, &f4, &f5};
        char *str_arr[] = {NULL, "1", "2x", "x^2 - 3x + 5", "e^x", "e^x + x^2 - 4"};
        while(1){

            printf("\n  (0) change eps\n");
            printf("  (1) f(x) = 1\n");
            printf("  (2) f(x) = 2x\n");
            printf("  (3) f(x) = x^2 - 3x + 5\n");
            printf("  (4) f(x) = e^x\n");
            printf("  (5) f(x) = e^x + x^2 - 4\n");
            printf("Select one of the functions: ");
            unsigned f_id;
            scanf("%u", &f_id);
            if(f_id == 0){
                eps = select_eps();
                continue;
            }
            double x1, x2;
            printf("\nSelect interval:\n  Left limit: ");
            scanf("%lf", &x1);
            printf("  Right limit: ");
            scanf("%lf", &x2);

            test(func_arr[f_id], eps, x1, x2, n++, str_arr[f_id]);

            printf("\nRun another test? [y/n] ");
            char c;
            scanf(" ");
            scanf("%c", &c);
            if (c == 'n') break;
        }
    } else {
        char *sep = "\n-----------------------------------\n\n";
        printf("\nTest #1\n");
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
    }

    return 0;
}