#include<time.h>
#include<string.h>

int main(int argc, char **argv)
{
        time_t rawtime;
        struct tm * timeinfo;
        char date[50];
	int days = 0;

	if(argc != 3)
	{
		printf("******* [USAGE] : %s <+/-> <Days> *******\n", argv[0]);
		exit(1);
	}

        time(&rawtime);
        timeinfo = localtime(&rawtime);

	days = atoi(argv[2]);
	if(days <= 0)
	{
		printf("Invalid no.of days - %d to +/- !!!\n", days);
		exit(1);
	}

	if(strcmp(argv[1], "+") == 0)
	{
	        rawtime = rawtime + (time_t)(days * 24 * 60 * 60);
	}
	else if(strcmp(argv[1], "-") == 0)
	{
        	rawtime = rawtime - (time_t)(days * 24 * 60 * 60);
	}
	else
	{
		printf("Invalid operation - %s !!!\n", argv[1]);
		exit(1);
	}

        strftime(date, 50, "%d %B %Y", timeinfo);
        printf("\tToday \t\t: %s\n", date);

        timeinfo = localtime(&rawtime);
        strftime(date, 50, "%d %B %Y", timeinfo);
        printf("\tNew Date \t: %s\n", date);
        return 0;
}
