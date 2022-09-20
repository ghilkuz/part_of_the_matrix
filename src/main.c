#include "part_of_the_matrix.h"

// Static function to free unused dynamic memory
static void free_memory(char *op1, char *operation, 
                        char *op2, char *res) {
    mx_strdel(op1);
    mx_strdel(operation);
    mx_strdel(op2);
    mx_strdel(res);
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        mx_printerr("usage: ./part_of_the_matrix ");
        mx_printerr("[operand1] [operation] [operand2] [result]\n");
        exit(-1);
    }
    // Create operands, operation, result and their lengths
    char *op1 = mx_strtrim(argv[1]);
    char *operation = mx_strtrim(argv[2]);
    char *op2 = mx_strtrim(argv[3]);
    char *res = mx_strtrim(argv[4]); 
    int op1_len = mx_strlen(op1);
    int operation_len = mx_strlen(operation);
    int op2_len = mx_strlen(op2);
    int res_len = mx_strlen(res);
    // Check if arguments are valid and free unused dynamic memory
    mx_check_args(argv, op1, operation, op2, res, op1_len, 
                  operation_len, op2_len, res_len);
    mx_realisation(op1, operation, op2, res, op1_len, op2_len, res_len);       
    free_memory(op1, operation, op2, res);
}

