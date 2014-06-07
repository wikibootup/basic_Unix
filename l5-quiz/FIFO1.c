#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//added
#include <signal.h>

int pd;

void handler(int signo)
{
	close(pd);
	remove("./fifo");
	exit(1);	
}

int main(void) {
	int n;
	char msg[] = "Hello, FIFO";

	//added
	void (*hand)(int);	

	printf("Server =====\n");

	if(mkfifo("./fifo", 0666) == -1) {
		perror("mkfifo");
		exit(1);
	}

	if((pd = open("./fifo", O_WRONLY)) == -1) {
		perror("open");
	}

	if((n == write(pd, msg, strlen(msg)+1)) == -1) {
		perror("write");
		exit(1);	
	}
	

	printf("To Client : %s\n", msg);

	while(1)
	{
		hand = signal(SIGINT, handler);
	}

		
	
	return 0;
	}
