
int my_isspace(char param_1)
{
  switch (param_1) {
    case ' ':
    case '\t':
    case '\n':
    case '\v':
    case '\f':
    case '\r':
      return 1;
    default:
      return 0;
  }
}
