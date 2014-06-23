#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include <netdb.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
	char buf[256];
//for socket
	struct sockaddr_in sin;
//	struct in_addr in;
	int sd;


//for socket
	memset((char*)&sin, '\0', sizeof(sin));
	sin.sin_family = AF_INET;
	sin.sin_port = htons( atoi(argv[2]) );
	sin.sin_addr.s_addr = inet_addr(argv[1]);

	if((sd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
		perror("socket");
		exit(1);
	}

	if(connect(sd, (struct sockaddr *)&sin, sizeof(sin))) {
		perror("connect");
		exit(1);
	}

	while(1) {

		if(recv(sd, buf, sizeof(buf), 0) == -1) {
			perror("recv");
			exit(1);
		}		
/*		gets(buf);	
		printf("c receive %s\n", buf);	

		if(send(sd, buf, strlen(buf)+1, 0) == -1) {
			perror("send");
			exit(1);
		}
*/
			printf("c2 receive %s\n", buf);	


	}

	return 0;
}
