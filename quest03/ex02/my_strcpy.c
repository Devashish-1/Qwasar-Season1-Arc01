

char* my_strcpy(char* param_1, char* param_2) {
  if (param_1 == 0 || param_2 == 0) {
    return 0;
  }
  while (*param_2 != '\0') {
    *param_1++ = *param_2++;
  }

  *param_1 = '\0';
  return param_1;
}
