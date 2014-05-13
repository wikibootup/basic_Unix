#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {
	if(argc != 2)
	{
		printf("USAGE : %s [1 OR 2 OR 3]\n", argv[0]);
		exit(0);
	}
	
	switch(atoi(argv[1])) {
		case 1:
			if( (mkdir("dir1", 0755) ) == -1) {
					perror("mk dir1");
					exit(0);
			}
			if( (mkdir("dir2", 0755) ) == -1) {
					perror("mk dir2");
					exit(0);
			}
			break;
		case 2:
			if( (rename("dir1", "redir1") ) == -1) {
				perror("mk dir1");
				exit(0);
			}
			break;
		case 3:
			if( (rmdir("dir2")) == -1) {
				perror("rm dir2");
				exit(0);
		}
		break;
	}
	return 0;
}
