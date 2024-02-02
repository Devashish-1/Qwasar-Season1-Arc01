#ifndef STRUCT_STRING_ARRAY
#define STRUCT_STRING_ARRAY
typedef struct s_string_array
{
    int size;
    char** array;
} string_array;
#endif

char* my_join(string_array* param_1, char* param_2) {
  if (param_1 == 0 || param_1->size == 0 || param_2 == 0) {
    return 0;
  }
  int total_length = 0;
  for (int i = 0; i < param_1->size; ++i) {
    total_length += strlen(param_1->array[i]);
    if (i > 0) {
      total_length += strlen(param_2);
    }
  }
  char* joined_string = malloc(sizeof(char) * (total_length + 1));
  if (joined_string == 0) {
    return 0;
  }
  joined_string[0] = '\0';
  for (int i = 0; i < param_1->size; ++i) {
    strcat(joined_string, param_1->array[i]);
    if (i < param_1->size - 1) {
      strcat(joined_string, param_2);
    }
  }
  return joined_string;
}
