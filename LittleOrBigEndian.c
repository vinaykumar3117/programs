#include <stdio.h>

int main()
{
  int a;
  if (*(char *) & a == 1)
    printf("Little endian system");
  else
    printf("Big endian system");
  return 0;
}
