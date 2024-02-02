#include "mastermind.h"
#include <string.h>
#include <stdlib.h>
#include <time.h>

void generateSecretCode(char *code) {
    srand(time(NULL));
    for (int i = 0; i < CODE_LENGTH; ++i) {
        code[i] = '0' + rand() % 9;
    }
    code[CODE_LENGTH] = '\0';
}

int isValidInput(const char *input) {
    if (strlen(input) != CODE_LENGTH) {
        return 0;
    }
    for (int i = 0; i < CODE_LENGTH; ++i) {
        if (input[i] < '0' || input[i] > '8') {
            return 0;
        }
    }
    return 1;
}

void evaluateGuess(const char *secretCode, const char *guess, int *wellPlaced, int *misplaced) {
    *wellPlaced = *misplaced = 0;

    for (int i = 0; i < CODE_LENGTH; ++i) {
        if (guess[i] == secretCode[i]) {
            (*wellPlaced)++;
        } else if (strchr(secretCode, guess[i]) != NULL) {
            (*misplaced)++;
        }
    }
}
