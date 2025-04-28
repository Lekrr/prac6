#include "main.h"

static struct {
    func_t f;
    func_t g;
    func_t f_der;
    func_t g_der;
} state;

static double F(double x){
    return state.f(x) - state.g(x);
}

static double F_der(double x){
    return state.f_der(x) - state.g_der(x);
}

double root(func_t f, func_t f_der, func_t g, func_t g_der, double a, double b, double eps1){

    state.f = f; state.g = g;
    state.f_der = f_der; state.g_der = g_der;

    double point = a, dir = 1;
    if (F(point) * F(point + eps1) < 0) return point;

    if(F_der(a) * (F_der(b) - F_der(a)) > 0){
        point = b;
        dir = -1;
    }
    
    while(F(point) * F(point + eps1 * dir) > 0){
        point = point - F(point) / F_der(point);
    }

    return point;
}