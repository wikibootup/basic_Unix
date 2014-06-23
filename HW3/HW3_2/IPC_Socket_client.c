#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include <netdb.h>
#include <string.h>
#include <stdlib.h>

//for pipe
#include <sys/wait.h>
#include <unistd.h>

//#define PORTNUM 5000
char msg[50] = {};

int main(int argc, char *argv[])
{
	char buf[256];
//for socket
	struct sockaddr_in sin;
//	struct in_addr in;
	int sd;

//for pipe
	int fd[2];
	pid_t pid;
	char msg[50];

//for socket
	memset((char*)&sin, '\0', sizeof(sin));
	sin.sin_family = AF_INET;
	sin.sin_port = htons( atoi(argv[2]) );
	sin.sin_addr.s_addr = inet_addr(argv[1]);

	if((sd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
		perror("socket");
		exit(1);
	}

//for pipe
	if(pipe(fd) == -1) {
		perror("pipe");
		exit(1);
	}
	

	if(connect(sd, (struct sockaddr *)&sin, sizeof(sin))) {
		perror("connect");
		exit(1);
	}

	sprintf(msg, "Number of Process in %s is ", argv[1]);
	write(1, msg, strlen(msg));

	system("ps -ef | wc -l");
/*
	switch(pid = fork() ) {
		case -1 :
			perror("fork");
			exit(1);
			break;
		case 0 :
			close(fd[1]);
			if(fd[0] != 0) {
				dup2(fd[0], 0);
				close(fd[0]);
			}
			execlp("wc", "wc", "-l", (char*)NULL);
			exit(1);
			break;
		default:
			close(fd[0]);
			if(fd[1] != 1) {
				dup2(fd[1], 1);
				close(fd[1]);
			}

//	printf("end\n");
//		if(send(sd, "q", 1, 0) == -1) {
//			perror("send");
//			exit(1);
//		}
			close(sd);
//
			execlp("ps", "ps", "-ef", (char*)NULL);
			wait(NULL);
			break;
	}
*/
/*
	while(1) {
			if(recv(ns, buf, sizeof(buf), 0) == -1) {
				perror("send");
				exit(1);
			}
	
			printf("** Client message: %s\n", buf);
	
		if(buf[0] != 'q')
			sprintf(buf, "%s", msg);
		else
			sprintf(buf, "Bye!!");
		
		if(send(ns, buf, strlen(buf), 0) == -1) {
			perror("send");
			exit(1);
		}
	}
*/
//	close(sd);
//	printf("end\n");

	return 0;
}
