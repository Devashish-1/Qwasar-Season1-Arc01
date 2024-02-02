
char* my_strdup(char* param_1) {
  if (*param_1 == '\0') {
    return "";
  }
  int length = strlen(param_1);
  char* new_string = malloc(sizeof(char) * (length + 1));
  if (new_string == 0) {
    return 0;
  }
  strcpy(new_string, param_1);
  return new_string;
}
