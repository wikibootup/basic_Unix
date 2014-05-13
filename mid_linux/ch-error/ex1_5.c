#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/errno.h>

extern int errno;
//char *strerror(int errnum);

int main(void)
{
	char *err;

	if(access("unix.txt", R_OK) == -1)
	{
		err = strerror(errno);
		printf("error : %s(unix.txt)\n", err);
		exit(1);
	}
	return 0;
}
