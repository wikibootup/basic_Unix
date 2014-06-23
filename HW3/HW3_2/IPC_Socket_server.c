#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include <string.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
	char buf[256];
	struct sockaddr_in sin, cli, cli2;
	struct in_addr in;
	int sd, ns, clientlen = sizeof(cli);
	int ns2, clientlen2 = sizeof(cli2);
	int n;

	if((sd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
		perror("socket");
		exit(1);
	}
	
	memset((char*)&sin, '\0', sizeof(sin));
	sin.sin_family = AF_INET;
	sin.sin_port = htons( atoi(argv[1]) );
	sin.sin_addr.s_addr = inet_addr("127.0.0.1");//server itself

	if(bind(sd, (struct sockaddr *)&sin, sizeof(sin))) {
		perror("bind");
		exit(1);
	}

	if(listen(sd,2)) {
		perror("listen");
		exit(1);
	}

	printf("*Wait Client!\n");
	if((ns = accept(sd, (struct sockaddr *)&cli, &clientlen)) == -1) {
		perror("accept");
		exit(1);
	}

	printf("*Client1 connected!!\n");

	if((ns2 = accept(sd, (struct sockaddr *)&cli2, &clientlen2)) == -1) {
		perror("accept");
		exit(1);
	}

	printf("*Client2 connected!!\n");

	while(1) {

			if(recv(ns, buf, sizeof(buf), 0) == -1) {
				perror("recv");
				exit(1);
			}

			if(strlen(buf)) {

				if(send(ns2, buf, strlen(buf)+1, 0) == -1) {
					perror("send");
					exit(1);
				}
			}
		
	}
	close(ns);
	close(ns2);
	close(sd);

	return 0;
}
