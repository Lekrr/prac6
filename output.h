#pragma once

char *help_message = "\
Usage: ./main [options]\n\
Options:\n\
    -help  Display this inforamtion\n\
    -a     Display the abscissa of intersection of functions\n\
    -i     Display the number of iterations of root function\n\
    -ti    Run program in testing mode for integral function\n\
    -tr    Run program in testing mode for root function\n";

void print_header(void){
    char *header = "\
+--------------------------+-----------+-----------+-----------+\n\
|                          |  f1 & f2  |  f1 & f3  |  f2 & f3  |\n\
+--------------------------+-----------+-----------+-----------+\n";
    printf(header);
}

void print_abscissas(double x1, double x2, double x3){
    char *s = "\
| Abscissa of intersection |  %-2.5lf |  %-2.5lf |  %-2.5lf |\n\
+--------------------------+-----------+-----------+-----------+\n";
    printf(s, x1, x2, x3);
}

void print_iter_cnt(unsigned i1, unsigned i2, unsigned i3){
    char *s = "\
| Number of irerations     |  %-8u |  %-8u |  %-8u |\n\
+--------------------------+-----------+-----------+-----------+\n";
    printf(s, i1, i2, i3);
}