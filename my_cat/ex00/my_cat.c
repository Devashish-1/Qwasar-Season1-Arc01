#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  // Check if at least one file is provided
  if (argc < 2) {
    fprintf(stderr, "Please provide at least one file path.\n");
    return 1;
  }

  // Loop through each file path and read its content
  for (int i = 1; i < argc; i++) {
    FILE *file = fopen(argv[i], "r"); // Declare and open the file

    // Check if file opened successfully
    if (!file) {
      fprintf(stderr, "Error opening file: %s\n", argv[i]);
      return 1;
    }

    char buffer[BUFSIZ];
    size_t bytes_read;

    while ((bytes_read = fread(buffer, 1, sizeof(buffer), file)) > 0) {
      for (int j = 0; j < bytes_read; j++) {
        printf("%c", buffer[j]);
      }
    }

    // Close the file
    fclose(file);
  }

  return 0;
}
