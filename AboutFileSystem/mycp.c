#include <stdio.h>
//for read(2), write(2)
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
	int rfd, wfd, n;
	char buf[BUFSIZ];

	char *fileName1 = argv[1];
	char *fileName2 = argv[2];

	rfd = open(fileName1, O_RDONLY);
	if(rfd == -1) {
		perror("Open original file");
		exit(1);
	}

	wfd = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if(wfd == -1) {
		perror("Open copy file");
		exit(1);
	}

//	buf[n] = '\0';
	while((n = read(rfd, buf, BUFSIZ)) > 0) {
	if(write(wfd, buf, n) != n) perror("Write");
	}

	if(n == -1)	perror("Read");	

	close(rfd);
	close(wfd);

	return 0;
}
