#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	int filedes;
	off_t newpos;

	filedes = open("data1.txt", O_RDONLY);

	/* r/w pointer is moved to EOF */
	newpos = lseek(filedes, (off_t)0, SEEK_END);

	printf("file size : %d\n", (int)newpos);
}
