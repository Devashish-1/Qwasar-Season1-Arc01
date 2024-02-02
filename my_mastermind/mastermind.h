#ifndef MASTERMIND_H
#define MASTERMIND_H

#define CODE_LENGTH 4
#define MAX_ATTEMPTS 10

void generateSecretCode(char *code);
int isValidInput(const char *input);
void evaluateGuess(const char *secretCode, const char *guess, int *wellPlaced, int *misplaced);

#endif
