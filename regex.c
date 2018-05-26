#include<stdio.h>
#include<stdlib.h>
#include<regex.h>
int main()
{
	/*regex_t r;
 	char *str = "This line conatins an exponenet number 777777777.77777e333 string one string two";
 	regmatch_t matches[4];
 	regcomp(&r, "([0-9]{7,9}\\.[0-9]{5}e[0-9]{2,3})", REG_EXTENDED);
 	regexec(&r, str, 4, matches, 0);
 	printf ("Found at %d\n",matches[1]);*/
	regex_t regex;
 	regmatch_t matches[2];
        int reti;
        char msgbuf[100];
 	char *str = "This line contains a number 477733 string one 4775689 string two";
	char *pat = "([0-9]+[a-z]*)";

	printf("lineno : 0123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789\n");
	printf("String : %s\nPattern: %s\n", str, pat);
/* Compile regular expression */
        reti = regcomp(&regex, pat, REG_EXTENDED);
        if( reti )
	{ 
		printf("Could not compile regex\n"); 
		exit(1); 
	}

/* Execute regular expression */
        reti = regexec(&regex, str, 2, matches, 0);
        if( !reti )
	{
                printf("Match at position %d, %d\n", matches[0], matches[1]);
        }
        else if( reti == REG_NOMATCH )
	{
                puts("No match!!!");
        }
        else
	{
                regerror(reti, &regex, msgbuf, sizeof(msgbuf));
                printf("Regex match failed: %s\n", msgbuf);
                exit(1);
        }

/* Free compiled regular expression if you want to use the regex_t again */
	regfree(&regex);
	return 0;
}
