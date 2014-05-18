#include <stdio.h>
//for opendir(3), closedir(3)
#include <sys/types.h>
#include <dirent.h>
//for exit(1)
#include <stdlib.h>

int main(int argc, char *argv[]) {
	DIR *dp;
	struct dirent *dent;
	
	if((dp = opendir(argv[1])) == NULL) {
			perror("opendir");
			exit(1);
	}

	while((dent = readdir(dp))) {
		if(dent ->d_name[0] != '.') {
			printf("Name : %s\n", dent ->d_name);
			printf("Inode : %d\n", (int)dent ->d_ino);
			printf("offset : %d\n", (int)dent ->d_off);
			printf("record length : %d\n", (int)dent ->d_reclen);
		}
	}
	
	close(dp);

	return 0;
}
