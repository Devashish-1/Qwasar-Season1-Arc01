#include <stdio.h>

void my_print_alphabet(void) {
  char ch = 'a';
  while (ch <= 'z') {
    putchar(ch);
    ch++;
  }
  putchar('\n');
}
