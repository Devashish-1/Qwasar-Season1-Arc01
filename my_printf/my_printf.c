#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdint.h>

#define CHAR_SIZE 1

// Function to write a single character to the standard output
int my_putchar(char c) {
    write(1, &c, 1);
    return CHAR_SIZE;
}

// Function to write a string to the standard output
int my_putstr(const char *str) {
    // Check for NULL string, if so, print "(null)"
    if (str == NULL) {
        return my_putstr("(null)");
    }

    int size = 0;
    while (*str != '\0') {
        size += my_putchar(*str);
        str++;
    }
    return size;
}

// Function to print a number with a specified base
int my_print_number(long long num, int base) {
    char NUMBERS[] = "0123456789ABCDEF";
    int size = 0;

    // Handle special case when the number is 0
    if (num == 0) {
        size += my_putchar('0');
        return size;
    }

    int is_negative = 0;
    // Handle negative numbers for base 10
    if (num < 0 && base == 10) {
        is_negative = 1;
        num = -num;
    }

    char buffer[20];
    int digits = 0;

    // Convert the number to the specified base
    while (num != 0) {
        int rem = num % base;
        buffer[digits++] = NUMBERS[rem < 0 ? -rem : rem];
        num /= base;
    }

    // Print '-' for negative numbers in base 10
    if (is_negative) {
        my_putchar('-');
        size++;
    }

    // Print the digits in reverse order
    for (int i = digits - 1; i >= 0; i--) {
        size += my_putchar(buffer[i]);
    }

    return size;
}

// Function to print a pointer value in hexadecimal format
int my_print_pointer(void *ptr) {
    uintptr_t intptr = (uintptr_t)ptr;
    int size = my_putchar('0') + my_putchar('x');
    char buffer[20];
    int digits = 0;

    // Convert the pointer value to hexadecimal
    while (intptr != 0) {
        int rem = intptr % 16;
        buffer[digits++] = (rem < 10) ? (rem + '0') : (rem - 10 + 'a');
        intptr /= 16;
    }

    // Print the digits in reverse order
    for (int i = digits - 1; i >= 0; i--) {
        size += my_putchar(buffer[i]);
    }

    return size;
}

// Function to implement custom printf functionality
int my_printf(const char *restrict format, ...) {
    int size = 0;
    va_list args;
    va_start(args, format);

    while (*format != '\0') {
        if (*format == '%') {
            format++;
            if (*format == 'd') {
                // Handle integer format specifier
                int num = va_arg(args, int);
                size += my_print_number(num, 10);
            } else if (*format == 'o') {
                // Handle unsigned octal format specifier
                unsigned int num = va_arg(args, unsigned int);
                size += my_print_number(num, 8);
            } else if (*format == 'x') {
                // Handle unsigned hexadecimal format specifier
                unsigned int num = va_arg(args, unsigned int);
                size += my_print_number(num, 16);
            } else if (*format == 'u') {
                // Handle unsigned decimal format specifier
                unsigned int num = va_arg(args, unsigned int);
                size += my_print_number(num, 10);
            } else if (*format == 'c') {
                // Handle character format specifier
                char c = va_arg(args, int);
                size += my_putchar(c);
            } else if (*format == 's') {
                // Handle string format specifier
                char *str = va_arg(args, char*);
                size += my_putstr(str);
            } else if (*format == 'p') {
                // Handle pointer format specifier
                void *ptr = va_arg(args, void*);
                size += my_print_pointer(ptr);
            }
        } else {
            // Ordinary character, print it
            size += my_putchar(*format);
        }
        format++;
    }

    va_end(args);
    return size;
}

// Main function for testing
int main() {
    // Test the custom printf function
    my_printf("Hello, %s! %d + %d = %d\n", "world", 5, 3, 5 + 3);
    return 0;
}
