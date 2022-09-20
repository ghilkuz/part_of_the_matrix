#include "part_of_the_matrix.h"

// Function to find out if result is invalid
void mx_invalid_result(char *res) {
    mx_printerr("Invalid result: ");
    mx_printerr(res);
    mx_printerr("\n");
    exit(-1);
}

