#include <stdbool.h>

#ifndef STRUCT_INTEGER_ARRAY
#define STRUCT_INTEGER_ARRAY

typedef struct s_integer_array {
  int size;
  int* array;
} integer_array;

#endif

bool my_is_sort(integer_array* param_1) {
  if (param_1 == 0 || param_1->size <= 1) {
    return true;
  }

  bool ascending = true;
  bool descending = true;
  int prev_value = param_1->array[0];
  for (int i = 1; i < param_1->size; ++i) {
    int current_value = param_1->array[i];

    if (current_value < prev_value) {
      ascending = false;
    }
    if (current_value > prev_value) {
      descending = false;
    }
    if (current_value == prev_value) {
      continue;
    }

    if (!ascending && !descending) {
      return false;
    }

    prev_value = current_value;
  }

  return ascending || descending;
}
