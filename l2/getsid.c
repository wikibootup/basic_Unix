#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
	pid_t pid;
	
	if(argc != 2)
	{
		printf("USAGE : %s [bashPID]\n", argv[0]);
		exit(0);
	}

	pid = atoi(argv[1]);

	printf("[1]process id : %d, group id : %d, session id : %d\n",
			pid, getpgid(pid), getsid(pid) );
	printf("[2]process id : %d, group id : %d, session id : %d\n",
			getpid(), getpgrp(), getsid(0) );

	return 0;
}
