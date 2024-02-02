#include "mastermind.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h> // Add this line

int main(int argc, char *argv[]) {
    char secretCode[CODE_LENGTH + 1];
    int attempts = MAX_ATTEMPTS;

    for (int i = 1; i < argc; i += 2) {
        if (strcmp(argv[i], "-c") == 0) {
            strncpy(secretCode, argv[i + 1], CODE_LENGTH);
            secretCode[CODE_LENGTH] = '\0';
        } else if (strcmp(argv[i], "-t") == 0) {
            attempts = atoi(argv[i + 1]);
        }
    }

    if (strlen(secretCode) == 0) {
        generateSecretCode(secretCode);
    }

    printf("Will you find the secret code?\nPlease enter a valid guess\n");

    for (int round = 0; round < attempts; ++round) {
        char guess[CODE_LENGTH + 1];
        int wellPlaced, misplaced;

        char c;
        int index = 0;
        while (read(0, &c, 1) > 0 && c != '\n') {
            if (index < CODE_LENGTH) {
                guess[index++] = c;
            }
        }
        guess[index] = '\0';

        if (!isValidInput(guess)) {
            printf("Wrong input!\n");
            continue;
        }

        evaluateGuess(secretCode, guess, &wellPlaced, &misplaced);

        if (wellPlaced == CODE_LENGTH) {
            printf("Congratz! You did it!\n");
            return 0;
        }

        printf("---\nRound %d\n> %s\nWell placed pieces: %d\nMisplaced pieces: %d\n", round, guess, wellPlaced, misplaced);
    }

    printf("Out of attempts. The secret code was: %s\n", secretCode);

    return 0;
}
