#ifndef STRUCT_STRING_ARRAY
#define STRUCT_STRING_ARRAY
typedef struct s_string_array
{
    int size;
    char** array;
} string_array;
#endif

#ifndef STRUCT_INTEGER_ARRAY
#define STRUCT_INTEGER_ARRAY
typedef struct s_integer_array
{
    int size;
    int* array;
} integer_array;
#endif

integer_array* my_count_on_it(string_array* param_1) {
  if (param_1 == 0|| param_1->size == 0) {
    return 0;
  }
  integer_array* result = malloc(sizeof(integer_array));
  if (result == 0) {
    return 0;
  }
  result->size = param_1->size;
  result->array = malloc(sizeof(int) * result->size);
  if (result->array == 0) {
    free(result);
    return 0;
  }
  for (int i = 0; i < param_1->size; ++i) {
    result->array[i] = strlen(param_1->array[i]);
  }
  return result;
}
