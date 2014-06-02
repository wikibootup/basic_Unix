#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
//added
#include <signal.h>
#include <siginfo.h>


int main(void) {
	int pd , n;
	char inmsg[80];
	//added
	struct sigaction act;

	sigemptyset(&act.sa_mask);
	sigaddset(&act.sa_mask, SIGQUIT);

	act.sa_flags = 0;
	act.sa_handler = handler;

	if((pd = open("./fifo", O_RDONLY)) == -1) {
		perror("open");
		exit(1);
	}

	//added
	if(sigaction(SIGINT, &act, (struct sigaction *)NULL) <0) {
		perror("sigaction");
		exit(1);
	}



	printf("Client =====\n");

	write(1, "From Server:", 13);

	while((n=read(pd, inmsg, 80)) > 0)
		write(1, inmsg, n);

	if(n == -1) {
		perror("read");
		exit(1);
	}

	write(1, "\n", 1);
	close(pd);

	return 0;
	}
