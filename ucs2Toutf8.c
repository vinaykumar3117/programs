#include<stdio.h>
#include<stdlib.h>
/* Returns no. of bytes written or -1 if error. Adds a zero byte to
   the end of the string. */
int HEX2DEC(char *s)
{
    	int x;
    	sscanf(s, "%x", &x);
	return x;
}
int ucs2_to_utf8 (int ucs2, unsigned char * utf8)
{
    if (ucs2 < 0x80) {
        utf8[0] = ucs2;
        utf8[1] = '\0';
        return 1;
    }
    if (ucs2 >= 0x80  && ucs2 < 0x800) {
        utf8[0] = (ucs2 >> 6)   | 0xC0;
        utf8[1] = (ucs2 & 0x3F) | 0x80;
        utf8[2] = '\0';
        return 2;
    }
    if (ucs2 >= 0x800 && ucs2 < 0xFFFF) {
        utf8[0] = ((ucs2 >> 12)       ) | 0xE0;
        utf8[1] = ((ucs2 >> 6 ) & 0x3F) | 0x80;
        utf8[2] = ((ucs2      ) & 0x3F) | 0x80;
        utf8[3] = '\0';
        return 3;
    }
    return -1;
}
int main(int argc,char **argv)
{
	unsigned char u8[100];
	/*ucs2_to_utf8(0x0C85,u8);
	printf("UTF8 : %s\n",u8);*/
	if(argc == 1)
	{
		printf("************* [Usage : %s <Unicode No> ...] *************\n",argv[0]);
		exit(1);
	}
	int dec = 0,i;
	printf("UTF8 :");
	for(i=1;i<argc;i++)
	{
		dec = HEX2DEC(argv[i]);
		ucs2_to_utf8(dec,u8);
		printf(" %s",u8);
	}
	printf("\n");
	return 0;
}
