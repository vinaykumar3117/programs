#include <stdio.h>

int main()
{
  int i, j, k, n;
  //printf("Enter n: ");
  //scanf("%d, &n");
  n = 4;
  for(i=0; i<n; i++)
  {
    j = n - i - 1;
    k = i * 2 + 1;
    while(j != 0)
    {
        printf(" ");
        j--;
    }
    while(k != 0)
    {
        printf("*");
        k--;
    }
    printf("\n");
  }
  return 0;
}
