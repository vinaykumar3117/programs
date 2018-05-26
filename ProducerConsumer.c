#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>
struct DATA
{
	int num;
	char string[100];
};
struct DATA data;
void *produce()
{
	printf("*** Producer Thread Started ***\n");
	int i;
	char buf[100];
	for(i=0;i<10;)	
	{
		if(strcmp(data.string, "") == 0)
                {
			sprintf(buf, "String %d", i+1);
			data.num = i+1;
			strcpy(data.string, buf);
			printf("+++++++++++++++++++++++++ Produced item %d -> %s\n", i+1, buf);
			fflush(stdout);
			i++;
		}
		else
		{
			printf("Waiting %d seconds for Consumer...\n", i);
			sleep(i);
		}
	}
	printf("*** Producer Thread Stopped ***\n");
}
void *consume()
{
	printf("*** Consumer Thread Started ***\n");
	int i;
	for(i=0;i<10;)
	{
		if(strcmp(data.string, "") == 0)
		{
			printf("Waiting 5 seconds for Producer...\n");
			sleep(5);
		}
		else
		{
			printf("------------------------- Consumed item %d -> %s\n", data.num, data.string);
			strcpy(data.string, "");
			i++;
		}
	}
	printf("*** Consumer Thread Stopped ***\n");
}
int main(int argc, char **argv)
{
	pthread_t producer, consumer;
	printf("Main Thread Started...\n");
	pthread_create(&producer, NULL, *produce, NULL);
	pthread_create(&consumer, NULL, *consume, NULL);
	pthread_join(producer, NULL);
	pthread_join(consumer, NULL);
	printf("Main Thread Terminated.\n");
	return 0;
}
