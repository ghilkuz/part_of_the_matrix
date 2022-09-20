#ifndef PART_OF_THE_MATRIX_H
#define PART_OF_THE_MATRIX_H

#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char *argv[]);

long long mx_atoi(const char *str);
bool mx_isdigit(int c);
bool mx_isspace(char c);
void mx_printchar(char c);
void mx_printint(int n);
void mx_printstr(const char *s);
int mx_strlen(const char *s);

double mx_pow(double n, unsigned int pow);
char *mx_strnew(const int size);
char *mx_strtrim(const char *str);
char *mx_strncpy(char *dst, const char *src, int len);
void mx_strdel(char *str);
void mx_printerr(const char *s);

char *mx_itoa(long long num);
void mx_check_args(char *argv[], char *op1, char *op2, 
                   char *operation, char *res, int op1_len, 
                   int operation_len, int op2_len, int res_len);
void mx_invalid_operand(char *op);
void mx_invalid_operation(char* operation);
void mx_invalid_result(char* res);

void mx_realisation(char *op1, char *operation, char *op2, char *res, 
                    int op1_len, int op2_len, int res_len);
                       
void mx_print_equation(int i, char *operation, int j, int k);

#endif
