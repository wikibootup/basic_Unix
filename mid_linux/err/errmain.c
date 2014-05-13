#include <stdio.h>
#include <sys/errno.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	if( access("unix.txt", R_OK) == -1) {
	perror("wow");
	exit(1);	
	}
	
	return 0;
}
