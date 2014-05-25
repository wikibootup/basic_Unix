#include <stdio.h>
//for atexit(3)
#include <stdlib.h>
//fr waitpid(), fork(2)
#include <sys/types.h>
#include <sys/wait.h>
//for exec series, fork(2)
#include <unistd.h>
//for open(2)
#include <sys/stat.h>
#include <fcntl.h>
//for strcmp
#include <string.h>

void byebye()
{
	printf("byebye~\n");
}

int main(int argc, char *argv[])
{
	int status;//for wait()
	pid_t pid[2];
	char *userInput;
	char *path;
	int i;
	int fd;
//	mode_t mode = S_IRUSR | S_IRGRP | S_IROTH;
	
//	while(1) {
			scanf("%s", userInput);

		if((pid[0] = fork()) == -1) { /* fork failed */
			perror("fork");			exit(1);	}
//		if((pid[1] = fork()) == -1) { /* fork failed */
//			perror("fork");			exit(1);	}

		if(pid[0] == 0) {// child process 
//			scanf("%s", userInput);
			printf("%s", userInput);
//			if((strcmp(userInput, "Quit")) != 0)			
				execlp(userInput, userInput, (char*)NULL);
//			else
//				break;
		}
		if(pid[0] != 0)	waitpid(pid[0], NULL, 0);
//		if(pid[1] != 0)	waitpid(pid[1], &status[1], 0);
		
//	}
	atexit(byebye);
	return 0;
}
