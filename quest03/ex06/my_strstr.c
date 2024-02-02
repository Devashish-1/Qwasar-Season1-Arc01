

char* my_strstr(char* param_1, char* param_2) {
  if (*param_2 == '\0') {
    return param_1;
  }

  while (*param_1 != '\0') {
    char* haystack_ptr = param_1;
    char* needle_ptr = param_2;
    while (*needle_ptr != '\0' && *haystack_ptr == *needle_ptr) {
      haystack_ptr++;
      needle_ptr++;
    }
    if (*needle_ptr == '\0') {
      return param_1;
    }
    param_1++;
  }

  return 0;
}
