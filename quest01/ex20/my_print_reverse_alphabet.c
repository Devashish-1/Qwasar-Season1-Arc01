#include <stdio.h>


void my_print_reverse_alphabet(void)
{
  for (char ch = 'z'; ch >= 'a'; ch--) {
    putchar(ch);
  }
  putchar('\n');
}
