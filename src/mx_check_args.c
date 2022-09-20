#include "part_of_the_matrix.h"

void mx_check_args(char *argv[], char *op1, char *operation, 
                   char *op2, char *res, int op1_len, 
                   int operation_len, int op2_len, int res_len) {
    // Check operation according to the priority
    if (operation_len != 1) mx_invalid_operation(argv[2]);
    // Check the first operand
    if (op1_len < 1) mx_invalid_operand(argv[1]);
    for (int i = 0; i < op1_len; i++) {
        if (i == 0 && op1[i] == '-') continue;
        if (op1[i] != '?' && !mx_isdigit(op1[i]))
            mx_invalid_operand(argv[1]);
    }
    // Check others cases of invalid operation
    if (*operation != '?' && *operation != '+' && *operation != '-' 
        && *operation != '*' && *operation != '/')
        mx_invalid_operation(argv[2]);
    // Check the second operand   
    if (op2_len < 1) mx_invalid_operand(argv[3]);
    for (int i = 0; i < op2_len; i++) {
        if (i == 0 && op2[i] == '-') continue;
        if (op2[i] != '?' && !mx_isdigit(op2[i]))
            mx_invalid_operand(argv[3]);
    }
    // Check result
    if (res_len < 1) mx_invalid_result(argv[4]);
    for (int i = 0; i < res_len; i++) {
        if (i == 0 && res[i] == '-') continue;
        if (res[i] != '?' && !mx_isdigit(res[i]))
            mx_invalid_result(argv[4]);
    }
}

