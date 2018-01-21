#include <stdio.h>

int main()
{
  int i, j, n;
  //printf("Enter n: ");
  //scanf("%d, &n");
  n = 4;
  for(i=n; i>0; i--)
  {
    j = i;
    while(j != 0)
    {
        printf("*");
        j--;
    }
    printf("\n");
  }
  return 0;
}
