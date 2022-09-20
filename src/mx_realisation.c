#include "part_of_the_matrix.h"

// Static function for processing operations, 
// which call function to print equations
static void processing_operation(char *operation, long long i, 
                                 long long j, long long k) {
    switch (*operation) {
        case '+':
            if (i + j == k) mx_print_equation(i, " + ", j, k);
            break;
            
        case '-':
            if (i - j == k) mx_print_equation(i, " - ", j, k);
            break;
            
        case '*':
            if (i * j == k) mx_print_equation(i, " * ", j, k);
            break;
            
        case '/' :
            if (j != 0 && i / j == k) 
                mx_print_equation(i, " / ", j, k);
            break;
            
        default: break;
    }                          
}

void mx_realisation(char *op1, char *operation, char *op2, char *res, 
                       int op1_len, int op2_len, int res_len) {
    if (*operation == '?') {
        mx_realisation(op1, "+", op2, res, op1_len, op2_len, res_len);
        mx_realisation(op1, "-", op2, res, op1_len, op2_len, res_len);
        mx_realisation(op1, "*", op2, res, op1_len, op2_len, res_len);
        mx_realisation(op1, "/", op2, res, op1_len, op2_len, res_len);
        exit(0);
    }
    
    bool op1_negative = false;
    bool op2_negative = false;
    bool res_negative = false;
    
    if (op1[0] == '-') {
        op1_negative = true;
        op1++;
        op1_len--;
    }
    
    if (op2[0] == '-') {
        op2_negative = true;
        op2++;
        op2_len--;
    }
    
    if (res[0] == '-') {
        res_negative = true;
        res++;
        res_len--;
    }
    
    long long num1 = mx_atoi(op1); // the first operand
    long long num2 = mx_atoi(op2); // the second operand
    long long num3 = mx_atoi(res); // the result

    // Find possible values of the first operand
    for (long long i = 0; i < mx_pow(10, op1_len); i++) {
        if (num1 > 0) i = num1;

        char *i_str = mx_itoa(i);
        int i_str_len = mx_strlen(i_str);
        bool isvalid_i = true;

        for (int a = 0; a < op1_len - i_str_len; a++)
            if (mx_isdigit(op1[a]) && op1[a] != '0') {
                isvalid_i = false;
                break;
            }
            
        int index_i = 0;
        
        for (int a = op1_len - i_str_len; a < op1_len; a++)
            if (op1[a] != '?' && op1[a] != i_str[index_i++]) {
                isvalid_i = false;
                break;
            }

        mx_strdel(i_str);

        if (!isvalid_i) continue;

        // Find possible values of the second operand
        for (long long j = 0; j < mx_pow(10, op2_len); j++) {  
            if (num2 > 0) j = num2;

            char *j_str = mx_itoa(j);
            int j_str_len = mx_strlen(j_str);
            bool isvalid_j = true;

            for (int a = 0; a < op2_len - j_str_len; a++)
                if (mx_isdigit(op2[a]) && op2[a] != '0') {
                    isvalid_j = false;
                    break;
                }
                
            int index_j = 0;
            
            for (int a = op2_len - j_str_len; a < op2_len; a++)
                if (op2[a] != '?' && op2[a] != j_str[index_j++]) {
                    isvalid_j = false;
                    break;
                }

            mx_strdel(j_str);

            if (!isvalid_j) continue;

            // Find possible values of the result           
            for (long long k = 0; k < mx_pow(10, res_len); k++) {
                if (num3 > 0) k = num3;

                char *k_str = mx_itoa(k);
                int k_str_len = mx_strlen(k_str);
                bool isvalid_k = true;

                for (int a = 0; a < res_len - k_str_len; a++)
                    if (mx_isdigit(res[a]) && res[a] != '0') {
                        isvalid_k = false;
                        break;
                    }
                    
                int index_k = 0;
                
                for (int a = res_len - k_str_len; a < res_len; a++)
                    if (res[a] != '?' && res[a] != k_str[index_k++]) {
                        isvalid_k = false;
                        break;
                    }

                mx_strdel(k_str);

                if (!isvalid_k) continue;
                
                // Processing operations and print equations
                if (op1_negative) i *= -1;
                if (op2_negative) j *= -1;
                if (res_negative) k *= -1;
                
                // Call static void function to process operation
                processing_operation(operation, i, j, k);
                                
                if (op1_negative) i *= -1;
                if (op2_negative) j *= -1;
                if (res_negative) k *= -1;
                
                if (num3 > 0) break;
            }
            
            if (num2 > 0) break;  
        }
        
         if (num1 > 0) break;  
    }
    
    if (op1_negative) op1--;
    if (op2_negative) op2--;
    if (res_negative) res--;
}

