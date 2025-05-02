#include "main.h"
#include <stdlib.h>

static double abs1(double x){
    return (x > 0) ? x : -x;
}

typedef struct List{
    double value;
    struct List *next;
} list;

static struct{
    list **arr;
    int size, capacity;
} free_buff;

void add_to_free(list *l){
    if(free_buff.arr == NULL){
        free_buff.capacity = 2;
        free_buff.arr = malloc(sizeof(list *) * free_buff.capacity);
        free_buff.size = 0;
    }

    if(free_buff.size == free_buff.capacity){
        free_buff.capacity *= 2;
        free_buff.arr = realloc(free_buff.arr, sizeof(list *) * free_buff.capacity);
    }

    free_buff.arr[free_buff.size++] = l;
}

static void free_from_buff(void){
    for(int i = 0; i < free_buff.size; i++){
        free(free_buff.arr[i]);
    }
    free(free_buff.arr);
}

static list *init_list(int n, double a, double b, func_t f){
    list *l = malloc(sizeof(list) * (n + 1));
    add_to_free(l);

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
    add_to_free(new_nodes);
    double delta = (b - a) / n;

    for(int i = 0; i < n >> 1; i++){
        new_nodes[i].value = f(a + delta * (2 * i + 1));
        new_nodes[i].next = l->next;
        l->next = &new_nodes[i];
        l = l->next->next;
    }
}

static double calc(func_t f, double a, double b, int n, list *l){
    double res = 0;
    n >>= 1;

    for(int i = 0; i < n; i++){
        res += l->value + 4 * l->next->value + l->next->next->value;
        l = l->next->next;
    }
    res *= (b - a);
    res /= 6 * n;

    return res;
}

double integral(func_t f, double a, double b, double eps2){
    free_buff.arr = NULL;
    int n = 20;
    list *l;
    l = init_list(n, a, b, f);

    double res = calc(f, a, b, n, l);
    n *= 2;
    update_list(l, n, a, b, f);
    double new_res = calc(f, a, b, n, l);
    
    while (abs1(res - new_res) >= eps2){
        res = new_res;
        n *= 2;
        update_list(l, n, a, b, f);
        new_res = calc(f, a, b, n, l);
    }

    free_from_buff();
    return new_res;
}