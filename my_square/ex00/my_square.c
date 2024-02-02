#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    if (argc != 3 || argv[1][0] == '\0' || argv[2][0] == '\0') {
        // Print an empty string for invalid input
        return 0;
    }

    int x = atoi(argv[1]);
    int y = atoi(argv[2]);

    if (x < 1 || y < 1) {
        // Print an empty string for invalid input
        return 0;
    }

    for (int i = 1; i <= x; i++) {
        for (int j = 1; j <= y; j++) {
            if ((i == 1 || i == x) && (j == 1 || j == y)) {
                printf("%c", 'o');
            } else if (i == 1 || i == x) {
                printf("%c", '-');
            } else if (j == 1 || j == y) {
                printf("%c", '|');
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}
