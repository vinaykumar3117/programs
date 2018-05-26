#include<stdio.h>
#include<stdlib.h>
int main(int argc, char **argv)
{
	char command[1024];
	//system("mailx \"abc@xyz.com\" -s \"Test Mail\" < sendMail.c");
	//system("echo \"Testing Message.\" | mail -s \"Test Mail\" abc@xyz.com -- -f abc@xyz.com");
	if(argc != 3)
	{
		printf("***** [Usage]: %s <mailID> <Subject> [body.txt] *****\n", argv[0]);
		exit(1);
	}
	if(strcmp(argv[2], "") == 0)
		sprintf(command, "mail %s -- -f %s < body.txt", argv[1], argv[1]);
	else
		sprintf(command, "mail -s %s %s -- -f %s < body.txt", argv[2], argv[1], argv[1]);
	//printf("CMD : %s\n", command);
	system(command);
	return 0;
}
