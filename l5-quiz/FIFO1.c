#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void) {
	int pd , n;
	char msg[] = "Hello, FIFO";

	printf("Server =====\n");

	if(mkfifo("./fifo", 0666) == -1) {
		perror("mkfifo");
		exit(1);
	}

	if((pd = open("./fifo", O_WRONLY)) == -1) {
		perror("open");
	}

	printf("To Client : %s\n", msg);

	if((n == write(pd, msg, strlen(msg)+1)) == -1) {
		perror("write");
		exit(1);
	}

	close(pd);

	return 0;
	}
