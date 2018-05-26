#include <stdio.h>
#include <stdlib.h>
int main(int argc,char **argv)
{
	if(argc != 2)
	{
		printf("************** [Usage : %s <HEX>] **************\n",argv[0]);
		exit(1);
	}
	int x;
    	sscanf(argv[1], "%x", &x);
    	printf("DEC = %u\n", x);
	return 0;
}
