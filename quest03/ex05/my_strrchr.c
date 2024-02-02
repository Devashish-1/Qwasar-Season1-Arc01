
char* my_strchr(char* param_1, char param_2) {
  if (param_1 == 0) {
    return 0;
  }

  while (*param_1 != '\0') {
    if (*param_1 == param_2) {
      return param_1; 
    }
    param_1++;
  }

  return 0;
}
