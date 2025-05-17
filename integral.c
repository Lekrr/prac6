#include <stdlib.h>
#include "main.h"

static double abs1(double x){
    return (x > 0) ? x : -x;
}

typedef struct List{
    double value;
    struct List *next;
} list;

static void free_list(list *l, int n){
    list *next;
    while(n >= 10){
        next = l->next;
        free(l);
        l = next;
        n >>= 1;
    }
}

static list *init_list(int n, double a, double b, func_t f){
    list *l = malloc(sizeof(list) * (n + 1));

    double delta = (b - a) / n;

    for(int i = 0; i <= n; i++){
        l[i].value = f(a + delta * i);
        if (i < n) l[i].next = &(l[i + 1]);
    }
    l[n].next = NULL;

    return l;
}

static void update_list(list *l, int n, double a, double b, func_t f){
    list *new_nodes = malloc(sizeof(list) * (n >> 1));
    double delta = (b - a) / n;

    for(int i = 0; i < n >> 1; i++){
        new_nodes[i].value = f(a + delta * (2 * i + 1));
        new_nodes[i].next = l->next;
        l->next = &new_nodes[i];
        l = l->next->next;
    }
}

static double calc(func_t f, double a, double b, int n, list *l){
    double res = l->value + 4 * l->next->value;
    l = l->next->next;
    n >>= 1;

    for(int i = 1; i <= n - 1; i++){
        res += 2 * l->value + 4 * l->next->value;
        l = l->next->next;
    }
    res += l->value;
    res *= (b - a);
    res /= 6 * n;

    return res;
}

// calcaulate integral of f ob the interval [a, b] with the accuracy of eps2
double integral(func_t f, double a, double b, double eps2){
    int n = 10;
    list *l;
    l = init_list(n, a, b, f);

    double res = calc(f, a, b, n, l);
    n *= 2;
    update_list(l, n, a, b, f);
    double new_res = calc(f, a, b, n, l);
    
    while (abs1(res - new_res) / 15. >= eps2){
        res = new_res;
        n *= 2;
        update_list(l, n, a, b, f);
        new_res = calc(f, a, b, n, l);
    }

    free_list(l, n);
    return new_res;
}