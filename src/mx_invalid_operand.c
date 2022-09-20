#include "part_of_the_matrix.h"

// Function to find out if operand is invalid
void mx_invalid_operand(char *op) {
    mx_printerr("Invalid operand: ");
    mx_printerr(op);
    mx_printerr("\n");
    exit(-1);
}

