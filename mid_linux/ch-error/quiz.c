#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/errno.h>
//sprintf : print in buffer


int main(int argc, char *argv[])
{
	int filedes, fdnew1, fdnew2;
	int n;
	ssize_t nread;
	off_t newpos;
	char buffer[1024];
//	mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;	

	while((n = getopt(argc, argv, "n:")) != -1) {
		switch (n) {
		case 'n' :
			filedes = open(argv[2], O_RDWR);
			//if(filedes == -1)
			//{perror("error");exit(1);}
			break;
		}

		while((n = getopt(argc, argv, "c")) != -1) {
		switch (n) {
		case 'c' :
	
			filedes = open(argv[2], O_RDWR | O_CREAT);
			break;	
		}
		}
		if(filedes == -1)
		{perror("error");exit(1);}
		
	}
	n = read(filedes, buffer, 1024);
	buffer[n] = '\0';
	printf("%s", buffer);
	close(filedes);

	return 0;
}
