

char* my_strncpy(char* param_1, char* param_2, int param_3) {
  if (param_1 == 0 || param_2 == 0 || param_3 <= 0) {
    return 0;
  }

  int copied_chars = 0;
  char* source_ptr = param_2;
  char* dest_ptr = param_1;

  while (*source_ptr != '\0' && copied_chars < param_3) {
    *dest_ptr++ = *source_ptr++;
    copied_chars++;
  }

  *dest_ptr = '\0';

  return param_1;
}
