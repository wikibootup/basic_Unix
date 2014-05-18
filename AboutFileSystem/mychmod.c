#include <stdio.h>
//for file access permission bits, struct stat, chmod(2)
#include <sys/stat.h>
//for data types
#include <sys/types.h>

int main(int argc, char *argv[])
{
	struct	stat buf;
	int accPer;
	char accType[3] = {'r','w','x'};
	int i;	

	if(argc == 2)
		stat(argv[1], &buf);
	else if(argc == 3) {
		stat(argv[2], &buf);
		printf("---original file access permission---\n");
	}
	else if(argc > 3)
		printf("USAGE : <OWNER><+-><rwx> [FILENAME]\n");
	//permission flag variable
	accPer = S_IRUSR;
//	printf("%d\n", accPer);
//	printf("%o\n", (buf.st_mode & 00777 ));

	while(accPer > 0) {
		for(i=0 ; i<3 ; i++) {
			if(buf.st_mode & accPer)
				printf("%c", accType[i]);
			else
				printf("-");
			accPer = accPer >> 1;
		}	
	}
	printf("\n");

/////////////modifying file access permission/////////////////
	if(argc == 3) {

	if(argv[1][0] == 'u') {
		if(argv[1][1] == '+') {
			for(i=2 ; i<5 ; i++) {
				if(argv[1][i] == 'r')
					buf.st_mode |= S_IRUSR;
				if(argv[1][i] == 'w')
					buf.st_mode |= S_IWUSR;
				if(argv[1][i] == 'x') 
					buf.st_mode |= S_IXUSR;
			}
		}
		else if(argv[1][1] == '-'){
			for(i=2 ; i<5 ; i++) {
				if(argv[1][i] == 'r')
					buf.st_mode &= ~S_IRUSR;
				if(argv[1][i] == 'w')
					buf.st_mode &= ~S_IWUSR;
				if(argv[1][i] == 'x') 
					buf.st_mode &= ~S_IXUSR;
			}
		}	
	}
	if(argv[1][0] == 'g') {
		if(argv[1][1] == '+') {
			for(i=2 ; i<5 ; i++) {
				if(argv[1][i] == 'r')
					buf.st_mode |= S_IRGRP;
				if(argv[1][i] == 'w')
					buf.st_mode |= S_IWGRP;
				if(argv[1][i] == 'x') 
					buf.st_mode |= S_IXGRP;
			}
		}
		else if(argv[1][1] == '-'){
			for(i=2 ; i<5 ; i++) {
				if(argv[1][i] == 'r')
					buf.st_mode &= ~S_IRGRP;
				if(argv[1][i] == 'w')
					buf.st_mode &= ~S_IWGRP;
				if(argv[1][i] == 'x') 
					buf.st_mode &= ~S_IXGRP;
			}
		}	
	}
	if(argv[1][0] == 'o') {
		if(argv[1][1] == '+') {
			for(i=2 ; i<5 ; i++) {
				if(argv[1][i] == 'r')
					buf.st_mode |= S_IROTH;
				if(argv[1][i] == 'w')
					buf.st_mode |= S_IWOTH;
				if(argv[1][i] == 'x') 
					buf.st_mode |= S_IXOTH;
			}
		}
		else if(argv[1][1] == '-'){
			for(i=2 ; i<5 ; i++) {
				if(argv[1][i] == 'r')
					buf.st_mode &= ~S_IROTH;
				if(argv[1][i] == 'w')
					buf.st_mode &= ~S_IWOTH;
				if(argv[1][i] == 'x') 
					buf.st_mode &= ~S_IXOTH;
			}
		}	
	}

	chmod(argv[2], buf.st_mode);

	printf("---modified file access permission---\n");
	accPer = S_IRUSR;

	while(accPer > 0) {
		for(i=0 ; i<3 ; i++) {
			if(buf.st_mode & accPer)
				printf("%c", accType[i]);
			else
				printf("-");
			accPer = accPer >> 1;
		}
	}
	printf("\n");
	}
	return 0;
}

