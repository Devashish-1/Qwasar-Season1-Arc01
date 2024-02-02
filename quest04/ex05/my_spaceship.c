#include <stdio.h>
#include <stdlib.h>

char* my_spaceship(char* param_1) {
    int x = 0, y = 0;
    char direction = 'u';  
    for (int i = 0; param_1[i] != '\0'; i++) {
        switch (param_1[i]) {
            case 'R':
                if (direction == 'u') {
                    direction = 'r';  
                } else if (direction == 'r') {
                    direction = 'd'; 
                } else if (direction == 'd') {
                    direction = 'l'; 
                } else {
                    direction = 'u';  
                }
                break;

            case 'L':
                if (direction == 'u') {
                    direction = 'l';
                } else if (direction == 'r') {
                    direction = 'u';  
                } else if (direction == 'd') {
                    direction = 'r';  
                } else {
                    direction = 'd'; 
                }
                break;

            case 'A':
                if (direction == 'u') {
                    y++;
                } else if (direction == 'r') {
                    x++; 
                } else if (direction == 'd') {
                    y--;
                } else {
                    x--;  
                }
                break;
        }
    }
    char* result = (char*)malloc(50);
    snprintf(result, 50, "{x: %d, y: %d, direction: '%c'}", x, y, direction);

    return result;
}

int main() {
    char* result = my_spaceship("RAARA");
    printf("Output: %s\n", result);
    free(result);

    return 0;
}
