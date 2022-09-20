#include "part_of_the_matrix.h"

// Function to find out if operation is invalid
void mx_invalid_operation(char *operation) {
    mx_printerr("Invalid operation: ");
    mx_printerr(operation);
    mx_printerr("\n");
    exit(-1);
}

