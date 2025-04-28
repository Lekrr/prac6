#include "main.h"

static double abs1(double x){
    return (x > 0) ? x : -x;
}

static double calc(func_t f, double a, double b, int n){

    double delta = (b - a) / (2 * n);
    double res = (f(a) + f(b)) / 2;

    for(int k = 1; k < n; k++){
        res += f(a + delta * 2 * k) + 2 * f(a + delta * (2 * k - 1));
    }
    res += 2 * f(b - delta);
    res /= 3;
    res *= 2 * delta;

    return res;
}

double integral(func_t f, double a, double b, double eps2){

    int n = 20;

    double res = calc(f, a, b, n);
    n *= 2;
    double new_res = calc(f, a, b, n);
    
    while (abs1(res - new_res) >= eps2){
        res = new_res;
        n *= 2;
        new_res = calc(f, a, b, n);
    }

    return new_res;
}