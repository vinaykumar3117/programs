#include <stdio.h>

int main()
{
  int i, j, n;
  //printf("Enter n: ");
  //scanf("%d, &n");
  n = 4;
  for(i=0; i<n; i++)
  {
    j = i + 1;
    while(j != 0)
    {
        printf("*");
        j--;
    }
    printf("\n");
  }
  return 0;
}
