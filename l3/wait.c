#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int status;
	pid_t pid;
	switch(pid = fork()) {
		case -1 : /* fork failed */
			perror("fork");
			break;
		case 0 : /* child process */
			printf("-> Child Process\n");
			exit(2);
			break;
		default : /* parent process */
			while(wait(&status) != pid)
				continue;
			printf("-> Parent Process\n");
			printf("Status: %d, %d#x\n", status, status);
			printf("Child process Exit Status : %d\n", status >> 8);
			break;
	}
	return 0;
}
