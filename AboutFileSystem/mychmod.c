#include <stdio.h>
//for file access permission bits, struct stat
#include <sys/stat.h>
//for struct stat, chmod
#include <sys/types.h>

int main(int argc, char *argv[])
{
	struct	stat buf;
	int accPer;
	char accType[3] = {'r','w','x'};
	int i;	

	stat(argv[2], &buf);

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

	return 0;
}

