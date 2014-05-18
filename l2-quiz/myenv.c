//for fgets(3), fputs(3)
#include <stdio.h>
//for extern char **environ
#include <stdlib.h>
//for getpid(), read(2)
#include <unistd.h>
//for open(2)
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
//for strcpy()
#include <string.h>
//for exit()
#include <stdlib.h>

//constant BUFSIZ is defined in stdio.h

//extern char **environ;

int main(int argc, char *argv[])
{	
	char buf[BUFSIZ];
	char result[BUFSIZ];
//	char **env;
//	char thisPID[20];

	int fd, n;
	int i = 0;

//	FILE *rfp;
//	char result[BUFSIZ];
//	char buf[BUFSIZ];


	if(argc == 1){
			sprintf(buf, "%d", (int)getpid() );
	}
	else if(argc == 2)
		strcpy(buf, argv[1]);
	else if(argc > 2) {
		printf("USAGE : <%s> OR <%s [procNUM]\n", argv[0], argv[0]);
	}

//sprintf(result, "ADD1 %s ADD2", buf);
	sprintf(result, "/proc/%s/environ", buf);
//	printf("%s\n", result);	
/*
	if( (rfp = fopen(result, "r")) == NULL) {
		perror("fopen : unix.txt");
		exit(1);
	}
	
	while(fgets(buf, BUFSIZ, rfp) != NULL) {
		fputs(buf, rfp);
	}
	
	fclose(rfp);

*/
	fd = open(result, O_RDONLY);	
	if(fd == -1) {
		perror("Open");
		exit(1);
	}

	n = read(fd, buf, BUFSIZ);
	if(n == -1) {
		perror("Read");
		exit(1);
	}
//	printf("%d", n);
	buf[n] = '\0';		
//	printf("%s\n\n\n", buf);

	while(i < n) {
		if(*(buf + i) != '\n') {
			printf("%c", *(buf + i++));
		}
		else {
			printf("%c", *(buf + i++));
			printf("\n");
		}
	}	
	printf("\n");
	
//	printf("RESULT : %s\n", result);
	close(fd);

	return 0;
}


