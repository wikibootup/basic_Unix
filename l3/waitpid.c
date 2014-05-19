#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int status;
	pid_t pid;
	if((pid = fork()) < 0) { /* fork failed */
		perror("fork");
		exit(1);
	}
	if(pid == 0) { /* child process */
		printf("-> Child process\n");
		sleep(3);
		exit(3);
	}
	printf("-> Parent process\n");
	while(waitpid(pid, &status, WNOHANG) == 0) {
		printf("Parent still wait...\n");
		sleep(1);
	}
	printf("Child Exit Status : %d\n", (status >> 8));

	return 0;
}
