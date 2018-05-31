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
        printf("TCP Client Terminated\n");
        exit(0);
}

int main()
{
	struct sockaddr_in addr;
	char msg[100];

        signal(SIGTERM, sighandler);
        signal(SIGINT, sighandler);
        signal(SIGSEGV, sighandler);

	printf("TCP Client started...\n");
	sock = socket(AF_INET, SOCK_STREAM, 0);
	if(sock == -1)
	{
		printf("Socket creation failed!!(%s)\n", strerror(errno));
		exit(1);
	}
	printf("Socket created...\n");

	addr.sin_family = AF_INET;
	addr.sin_port = htons(1500);
	addr.sin_addr.s_addr = inet_addr("192.168.128.128");
/*
	if(inet_pton(AF_INET, "localhost", &addr.sin_addr) < 0)
	{
		printf("inet_pton error(%s)!!!\n", strerror(errno));
		close(sock);
		exit(1);
	}
*/

	if(connect(sock, (struct sockaddr *)&addr, sizeof(struct sockaddr)) < 0)
	{
		printf("connect failed(%s)!!!\n", strerror(errno));
		close(sock);
		exit(1);
	}
	printf("Connected to server...\n");
	
	memset(msg, '\0', sizeof(msg));
	if(recv(sock, msg, sizeof(msg), 0) <= 0)
	{
		printf("Unable to recv(%s)!!!\n", strerror(errno));
		close(sock);
		exit(1);
	}
	printf("Message from server : %s\n", msg);

	close(sock);
	printf("TCP Client terminated\n");
	return 0;
}
