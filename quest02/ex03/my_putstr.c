

#include <stdio.h>

void my_putstr(char* param_1) {
    while (*param_1 != '\0') {
        putchar(*param_1);
        param_1++;
    }
}
