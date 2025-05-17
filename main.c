#include <stdio.h>
#include <string.h>
#include "functions.h"
#include "root.h"
#include "integral.h"
#include "output.h"
#include "test_integral.h"
#include "test_root.h"

static double eps1 = 10e-4, eps2 = 10e-4;

int main(int argc, char *argv[]){

    // additional options flags
    int abscissas_print = 0, iter_count_print = 0;
    // numbers of iteration of root funtion
    unsigned i1, i2, i3;

    // handle main function parametrs
    for(int i = 1; i < argc; i++){
        if(strcmp(argv[i], "-help") == 0){
            printf(help_message);
            return 0;
        } else
        if(strcmp(argv[i], "-i") == 0){
            iter_count_print = 1;
        } else
        if(strcmp(argv[i], "-a") == 0){
            abscissas_print = 1;
        } else
        if(strcmp(argv[i], "-ti") == 0){
            return test_integral();
        } else
        if(strcmp(argv[i], "-tr") == 0){
            return test_root();
        } 
    }

    // intersacition of f1 and f2
    double x1 = root(f1, f1_der, f2, f2_der, -1, -0.2, eps1);
    i1 = iter_cnt;
    // intersacition of f1 and f3
    double x2 = root(f1, f1_der, f3, f3_der, -4.5, -3, eps1);
    i2 = iter_cnt;
    // intersacition of f2 and f3
    double x3 = root(f2, f2_der, f3, f3_der, -2, -1, eps1);
    i3 = iter_cnt;

    // output addition information based of flags
    if(abscissas_print || iter_count_print){
        print_header();
        if(abscissas_print) print_abscissas(x1, x2, x3);
        if(iter_count_print) print_iter_cnt(i1, i2, i3);
        printf("\n");
    }

    // calculate integrals
    double I1 = integral(&f1, x2, x1, eps2);
    double I2 = integral(&f2, x3, x1, eps2);
    double I3 = integral(&f3, x2, x3, eps2);

    double res = I1 - I2 - I3;
    printf("Calculated area: %lf\n", res);

    return 0;
}