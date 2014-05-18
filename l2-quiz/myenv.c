#include <stdio.h>
//for extern char **environ
#include <stdlib.h>
//for getpid()
#include <unistd.h>
//for strcpy()
#include <string.h>

extern char **environ;

int main(int argc, char *argv[])
{	
	char buf[BUFSIZ];
	char result[BUFSIZ];
	char **env;

	int n;
	extern char *optarg;
	extern int optind;
	
	if(argc == 1){
			sprintf(buf, "%d", (int)getpid() );
//			env = environ;
//			while(*env) {
//				printf("%s\n", *env);
//				env++;
//			}
	}
	else if(argc == 2)
		strcpy(buf, argv[1]);
	else if(argc > 2) {
		printf("USAGE : <%s> OR <%s [procNUM]\n", argv[0], argv[0]);
	}

//sprintf(result, "ADD1 %s ADD2", buf);
	sprintf(result, "/proc/%s/environ", buf);	
	printf("RESULT : %s\n", result);


	return 0;
}

