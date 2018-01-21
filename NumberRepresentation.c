#include <stdio.h>

int convert(int i)
{
  int j;
  for(j=0; j<16; j++)
  {
    if(i & (0x8000 >> j))
      printf("1");
    else
      printf("0");
  }
}

int main()
{
  int i;
  printf("Binary\t\tDecimal\tHexa\tOctal\n");
  for(i=1; i<101; i++)
    printf(" %d\t%X\t%o \n", i, i, i, convert(i));
  return 0;
}
