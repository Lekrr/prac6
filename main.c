#include <stdio.h>
#include <string.h>
#include "functions.h"
#include "root.h"
#include "integral.h"

static double eps1 = 0.001, eps2 = 0.001;

int main(int argc, char *argv[]){

    int abscissas_print = 0, iter_count_print = 0;

    for(int i = 1; i < argc; i++){
        if(strcmp(argv[i], "-help") == 0){
            printf("help mode\n");
            return 0;
        } else
        if(strcmp(argv[i], "-i") == 0){
            iter_count_print = 1;
            printf("iter count print\n");
        } else
        if(strcmp(argv[i], "-a") == 0){
            abscissas_print = 1;
            printf("abscissas print\n");
        }
    }

    double x1 = root(f1, f1_der, f2, f2_der, -1, -0.2, eps1);
    if(abscissas_print) printf("f1 and f2 intersect at %.5lf\n", x1);
    if(iter_count_print) printf("f1 f2: %d iterations\n", iter_cnt);
    double x2 = root(f1, f1_der, f3, f3_der, -4.5, -3, eps1);
    if(abscissas_print) printf("f1 and f3 intersect at %.5lf\n", x2);
    if(iter_count_print) printf("f1 f3: %d iterations\n", iter_cnt);
    double x3 = root(f2, f2_der, f3, f3_der, -2, -1, eps1);
    if(abscissas_print) printf("f2 and f3 intersect at %.5lf\n", x3);
    if(iter_count_print) printf("f2 f3: %d iterations\n", iter_cnt);

    double I1 = integral(&f1, x2, x1, eps2);
    double I2 = integral(&f2, x3, x1, eps2);
    double I3 = integral(&f3, x2, x3, eps2);

    double res = I1 - I2 - I3;
    printf("%lf\n", res);

    return 0;
}