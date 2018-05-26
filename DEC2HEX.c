#include <stdio.h>
#include <stdlib.h>
int main(int argc,char **argv)
{
	if(argc != 2)
	{
		printf("************** [Usage : %s <DEC>] **************\n",argv[0]);
		exit(1);
	}
	unsigned int x;
	unsigned char *xptr = (unsigned char *)&x;
    	sscanf(argv[1], "%x", &x);
    	printf("HEX = %s\n", *xptr);
	return 0;
}
