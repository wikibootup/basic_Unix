#include <stdio.h>
//for opendir(3), closedir(3)
#include <sys/types.h>
#include <dirent.h>
//for exit(1), stat()
#include <stdlib.h>

int main(int argc, char *argv[]) {
	DIR *dp;
	struct dirent *dent;
	struc stat buf;
	int kind;
	
	if((dp = opendir(".")) == NULL) {
			perror("opendir");
			exit(1);
	}

	while((dent = readdir(dp))) {
		stat(dent ->d_name, &buf);
		printf("Name : %s	", dent ->d_name);
		if((buf.st_mode & S_IFMT == S_IFDIR)
			printf("Kind : directory\n");
		else
			printf("kind : file]\n");
	}
	
	close(dp);

	return 0;
}
