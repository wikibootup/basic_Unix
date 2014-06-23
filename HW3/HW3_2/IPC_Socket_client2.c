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
	char temp[256];
//for socket
	struct sockaddr_in sin;
//	struct in_addr in;
	int sd;
	int n=0;

//for socket
	memset((char*)&sin, '\0', sizeof(sin));
	sin.sin_family = AF_INET;
	sin.sin_port = htons( atoi(argv[2]) );
	sin.sin_addr.s_addr = inet_addr(argv[1]);

	memset(buf, 0, sizeof(buf));
	memset(temp, 0, sizeof(temp));

	if((sd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
		perror("socket");
		exit(1);
	}

	if(connect(sd, (struct sockaddr *)&sin, sizeof(sin))) {
		perror("connect");
		exit(1);
	}

	while(1) {
		
		if(n = (recv(sd, buf, sizeof(buf), 0)) == -1)  {
			perror("recv");
			exit(1);
		}

//	if(n>0)
		if(strlen(buf) ) {
			printf("%s\n", buf);
//			break;
			memset(buf, 0, sizeof(buf));
		}
//		n = 0;

	}
	
	close(sd);

	return 0;
}
