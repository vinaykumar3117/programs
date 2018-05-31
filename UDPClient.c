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
        printf("UDP Client terminated\n");
        exit(0);
}

int main()
{
	char msg[100];
	struct sockaddr_in addr;

	signal(SIGINT,sighandler);
        signal(SIGTERM,sighandler);
        signal(SIGSEGV,sighandler);

	printf("UDP Client started...\n");
	sock = socket(AF_INET, SOCK_DGRAM, 0);
	if(sock == -1)
	{
		printf("Socket creation failed(%s)!!!\n",strerror(errno));
		exit(0);
	}
	printf("Socket created...\n");

	addr.sin_family = AF_INET;
	addr.sin_port = htons(1600);
	addr.sin_addr.s_addr = inet_addr("192.168.128.128");

	memset(msg,'\0',sizeof(msg));
	strcpy(msg,"yo server! wats up.....");
	sendto(sock, msg, sizeof(msg), 0, (struct sockaddr *)&addr, sizeof(struct sockaddr));
	printf("Message sent successfully...\n", msg);
	memset(msg,'\0',sizeof(msg));
	recvfrom(sock, msg, sizeof(msg), 0, NULL, NULL);
	printf("Response : %s\n", msg);

	close(sock);
	printf("UDP Client terminated\n");
	return 0;
}
