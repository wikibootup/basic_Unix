#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include <string.h>
#include <stdlib.h>

//#define PORTNUM 5000
char msg[50] = {};
const char* serverIP = "127.0.0.1";

int main(int argc, char *argv[])
{
	char buf[256];
	int n;
	struct sockaddr_in sin, cli;
	struct in_addr in;
	int sd, ns, clientlen = sizeof(cli);
	char msg[30];


	if((sd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
		perror("socket");
		exit(1);
	}
	
	memset((char*)&sin, '\0', sizeof(sin));
	sin.sin_family = AF_INET;
	sin.sin_port = htons( atoi(argv[1]) );
	sin.sin_addr.s_addr = inet_addr(serverIP);//server itself

	if(bind(sd, (struct sockaddr *)&sin, sizeof(sin))) {
		perror("bind");
		exit(1);
	}

	if(listen(sd,1)) {
		perror("listen");
		exit(1);
	}

//	printf("Wait Client!!!!!!!!!!!!!!!!!\n");
	if((ns = accept(sd, (struct sockaddr *)&cli, &clientlen)) == -1) {
		perror("accept");
		exit(1);
	}

	sprintf(msg, "Number of Process in %s is ", serverIP);
	

	write(1, msg, strlen(msg));

	system("ps -ef | wc -l");

//	write(1, "\n", 1);

//	exit(1);

//	printf("Client connected!!\n");

			close(ns);
			close(sd);

	return 0;
}
