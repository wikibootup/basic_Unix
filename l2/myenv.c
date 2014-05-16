#include <stdio.h>
//#include <stdlib.h>
//for getpid()
#include <unistd.h>
//for strcpy()
#include <string.h>

int main(int argc, char *argv[])
{	
	char buf[BUFSIZ];
	char result[BUFSIZ];

	int n;
	extern char *optarg;
	extern int optind;
	
	if(argc == 1){
		  ((int)getpid() );
		sprintf(buf, "%d", getpid() );
	}
	else if(argc == 2)
		strcpy(buf, argv[1]);
	else if(argc > 2) {
		printf("USAGE : <%s> OR <%s [procNUM]\n", argv[0], argv[0]);
	}

	sprintf(result, "ADD1 %s ADD2", buf);
	printf("RESULT : %s\n", result);

	

	return 0;
}

