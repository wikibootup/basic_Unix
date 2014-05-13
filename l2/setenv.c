#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

extern char **environ;
void printenv();

int main(int argc, char *argv[]) {
	if(argc != 4) {
		printf("USAGE : %s [ENVNAM] [ENVVAL] [0 OR 1]\n",
			argv[0]);
		exit(0);
	}

	setenv(argv[1], argv[2], atoi(argv[3]) );
	printenv();

	printf("\nUNSET = [ENTER]\n");
	getchar();

	if(0!=unsetenv(argv[1]) ) {
		perror("unset");
		exit(0);
	}

	printenv();
	printf("\nunset success!\n");

	return 0;
}
void printenv() {
	char **env;
	env = environ;
	while(*env) {
		printf("%s\n", *env);
		env++;
	}
}
