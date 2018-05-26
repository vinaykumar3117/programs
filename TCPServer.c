#include<stdio.h>
#include<errno.h>
#include<signal.h>
#include<sys/socket.h>
#include<netinet/in.h>

int sock;

void sighandler()
{
	printf("Received signal!!!\n");
	close(sock);
	printf("TCP Server Terminated\n");
	exit(0);
}

int main()
{
	int clnsock;
	struct sockaddr_in addr;
	char msg[100];
	int cnt = 0;
	
	signal(SIGTERM, sighandler);
	signal(SIGINT, sighandler);
	signal(SIGSEGV, sighandler);

	printf("TCP Server Started...\n");
	sock = socket(AF_INET, SOCK_STREAM, 0);
	if(sock == -1)
	{
		printf("Socket creation error(%s)!!!\n", strerror(errno));
		exit(1);
	}
	printf("Socket created...\n");

	addr.sin_family = AF_INET;
	addr.sin_port = htons(1500);
	addr.sin_addr.s_addr = INADDR_ANY;

	if(bind(sock, (struct sockaddr *)&addr, sizeof(struct sockaddr)))
	{
		printf("Bind failed(%s)!!!\n", strerror(errno));
		close(sock);
		exit(1);
	}
	printf("Bound to the socket...\n");
	
	if(listen(sock, 5))
	{
		printf("unable to listen(%s)!!!\n", strerror(errno));
		close(sock);
		exit(1);
	}
	printf("Listening at port 1500...\n");

	while(1)
	{
		memset(msg, '\0', sizeof(msg));
		clnsock = accept(sock, (struct sockaddr *)NULL, NULL);
		if(clnsock == -1)
		{
			printf("Unable to accept client connection(%s)!!!\n", strerror(errno));
			exit(1);
		}
		printf("Client connected %d\n", ++cnt);

		sprintf(msg, "hello buddy... %d", cnt);
		if(send(clnsock, msg, strlen(msg), 0) == -1)
			printf("Message sending failed(%s)!!!\n", strerror(errno));
		else
			printf("Message sent successfully...\n");
		close(clnsock);
		sleep(1);
	}
}
