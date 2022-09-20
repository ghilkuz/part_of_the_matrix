#include "part_of_the_matrix.h"

// Function to print equation to the standard output
void mx_print_equation(int i, char *operation, int j, int k) {
    mx_printint(i);
    mx_printstr(operation);
    mx_printint(j);
    mx_printstr(" = ");
    mx_printint(k);
    mx_printchar('\n');
}

