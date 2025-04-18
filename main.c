#include <stdio.h>
#include <string.h>
#include "functions.h"
#include "root.h"
#include "integral.h"

int main(int argc, char *argv[]){

    int abscissas_print = 0, iter_count_print = 0;

    for(int i = 0; i < argc; i++){
        if(strcmp(argv[i], "--help") == 0){
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

    return 0;
}   