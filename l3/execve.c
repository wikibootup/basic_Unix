#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char *argv[3];
	char *envp[2];

	printf("Befoe exec function");
	argv[0] = "arg";
	argv[1] = "100";
	argv[2] = NULL;

	envp[0] = "My env = System_programming";
	envp[1] = NULL;

	if(execve("./arg", argv, envp) == -1) {
		perror("execve");
		exit(1);
	}
	printf("->After exec function\n");

	return 0;
}
