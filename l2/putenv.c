#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

extern char **environ;

int main(int argc, char *argv[]) {
	char **env;
	
	if(argc != 2)
	{
		printf("USAGE : %s [ envNAM = envVAL ]\n", argv[0]);
		exit(0);
	}

	if(0 != putenv(argv[1]) ){
		perror("putenv");
		exit(0);
	}

	env = environ;
	while(*env) {
		printf("%s\n", *env);
		env++;
	}

	return 0;
}
