#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char *argv[]) {
	char *cwd;

	if(NULL == (cwd = getcwd(NULL, BUFSIZ)) ) {
		perror("getcwd1");
		exit(0);
	}
	printf("1. Current Dir : %s\n", cwd);

	if(-1 == chdir("/") ) {
		perror("chdir");
		exit(0);
	}

	if(NULL == (cwd = getcwd(NULL, BUFSIZ)) ) {	
		perror("getcwd2");
		exit(0);
	}
	printf("2. Current Dir : %s\n", cwd);

	return 0;
}
