#include "part_of_the_matrix.h"

char *mx_itoa(long long num) {
    char *str = NULL;

    if (num == 0) {
        str = mx_strnew(1);
        str[0] = '0';
        return str;
    }

    int length = 0;
    long long copy_num = num;

    if (copy_num < 0) {
        copy_num *= -1;
        length++;
    }
    for (; copy_num != 0; length++) 
        copy_num /= 10;
    str = mx_strnew(length);
    
    if (num < 0) {
        str[0] = '-';
        num *= -1;
    }
    str[length--] = '\0';
    for (; (num != 0 && length >= 0) && str[length] != '-'; num /= 10) 
        str[length--] = (num % 10) + '0';
    return str;
}

