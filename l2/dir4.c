#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>

int main(int argc, char *argv[])
{
	printf("PID			:%d\n",(int)getpid());
	printf("PGRP		:%d\n", (int)getpgrp() );
	printf("PGID(pid)	: %d\n", (int)getpgid(getpid()) );
	printf("PGID(0)		: %d\n", (int)getpgid(0) );

	if(argc == 2)
	{
		printf("PGID(%s) : %d\n", argv[1])
					, (int)(getpgid(atoi(argv[1]))) ;

	}
	return 0;
}
