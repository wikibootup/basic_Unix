#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
//added
#include <signal.h>

int pd;

void handler(int signo)
{
	close(pd);
	exit(1);
}


int main(void) {
	int n;
	char inmsg[80];

	if((pd = open("./fifo", O_RDONLY)) == -1) {
		perror("open");
		exit(1);
	}

	//added
	void (*hand)(int);

	printf("Client =====\n");

while(1)
{
	hand = signal(SIGINT, handler);
	
//	getchar();

	while((n = read(pd, inmsg, 80)) >0)
		write(1, inmsg, n);

	if(n == -1) {
		perror("read");
		exit(1);
	}
}
		return 0;
}
