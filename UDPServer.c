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
	printf("UDP Server terminated\n");
	exit(0);
}

int main()
{
	char msg[100],ACK[100];
	int len, cnt = 0;
	struct sockaddr_in srvaddr, clnaddr;

	signal(SIGINT,sighandler);
	signal(SIGTERM,sighandler);
	signal(SIGSEGV,sighandler);
	
	printf("UDP Server Started...\n");
	sock = socket(AF_INET, SOCK_DGRAM, 0);
	if(sock == -1)
	{
		printf("Socket creation failed(%s)!!!\n", strerror(errno));
		exit(1);
	}
	printf("Socket created...\n");
	
	srvaddr.sin_family = AF_INET;
	srvaddr.sin_port = htons(1600);
	srvaddr.sin_addr.s_addr = INADDR_ANY;

	if(bind(sock, (struct sockaddr *)&srvaddr, sizeof(struct sockaddr)) < 0)
	{
		printf("Unable to bind(%s)!!!\n", strerror(errno));
                close(sock);
                exit(1);
	}
	printf("Bound to the socket...\n");

	while(1)
	{
		memset(msg, '\0', sizeof(msg));
		len = sizeof(clnaddr);
		recvfrom(sock, msg, sizeof(msg), 0, (struct sockaddr *)&clnaddr, &len);
		printf("Message from client %d : %s\n", ++cnt, msg);
		sprintf(ACK, "ACK-%d %s", cnt, msg);
		sendto(sock, ACK, sizeof(ACK), 0, (struct sockaddr *)&clnaddr, sizeof(clnaddr));
		sleep(1);
	}
}
