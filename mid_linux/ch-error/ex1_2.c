#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#define BUFFER 32

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		printf("USAGE : %s [FILE NAME]\n", argv[0]);
		exit(1);
	}

	int fd;
	char *filename = argv[1];
	if(fd = open(filename, O_RDWR) == -1)
	{
		char *error;
		error = (char *)malloc((sizeof(char)*BUFFER) + sizeof(char)*sizeof(argv[1]));
		sprintf(error, "open error [%s]", filename);
		perror(error);
	}
	close(fd);
	return 0;
}
