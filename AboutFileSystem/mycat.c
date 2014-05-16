#include <stdio.h>
//for read(2)
#include <unistd.h>
//for open(2)
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
//for exit()
#include <stdlib.h>

//constant BUFSIZ is defined in stdio.h


int main(int argc, char *argv[])
{
	int fd, n;
	char buf[BUFSIZ];

	char *fileName = argv[1];

	fd = open(fileName, O_RDONLY);
	if(fd == -1) {
		perror("Open");
		exit(1);
	}
	
	n = read(fd, buf, BUFSIZ);
	if(n == -1) {
		perror("Read");
		exit(1);
	}

	buf[n] = '\0';
	printf("%s", buf);
	close(fd);

	return 0;
}
