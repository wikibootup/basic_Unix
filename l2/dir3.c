#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <errno.h>

int main(int argc, char *argv[]) {

	DIR *dp;
	struct dirent *dent;
	int n;

	n = 0;

	if(argc > 2)
	{
		printf("USAGE : <%s>, <%s [dir]> \n", argv[0], argv[0]);
		exit(0);
	}
	if(argc == 1)
		if( (dp = opendir(".")) == NULL) {
			perror("opendir : redir1");
			exit(0);
		}
	if(argc == 2)
	{
		if( (dp = opendir(argv[1])) == NULL) {
			perror("opendir : redir1");
			exit(0);
		}
	}
	
	while( (dent = readdir(dp)) ) {
		printf("%35s", dent ->d_name);
		n++;
		if(n == 2)
		{
			printf("\n");
			n = 0;
		}
	}
	printf("\n");
	
	closedir(dp);
	return 0;
}
