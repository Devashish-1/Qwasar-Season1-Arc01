
char* reverse_string(char* param_1) {
  if (*param_1 == '\0') {
    return param_1;
  }
  char* start = param_1;
  char* end = param_1 + strlen(param_1) - 1;

  while (start < end) {
    char temp = *start;
    *start = *end;
    *end = temp;

    start++;
    end--;
  }

  return param_1;
}
