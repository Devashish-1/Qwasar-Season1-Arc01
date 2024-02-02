/*
**
** QWASAR.IO -- my_string_formatting
**
** @param {char*} param_1 (firstname)
** @param {char*} param_2 (lastname)
** @param {int} param_3 (age)
**
** @return {void}
**
*/

void my_string_formatting(char* param_1, char* param_2, int param_3) {
  // Construct the formatted message
  char message[100];
  sprintf(message, "Hello, my name is %s %s, I'm %d.\n", param_1, param_2, param_3);

  // Print the message
  printf("%s", message);
}
