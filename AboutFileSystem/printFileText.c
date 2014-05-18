//for tmpnam(3), write(2)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//BUFSIZ if defined in stdio.h
int main(void)
{
	char *fname;
	char fntmp[BUFSIZ];
	char template[32];

	int wfd, n;
	char buf[BUFSIZ]

	fname = tmpnam(NULL);
	printf("1. TMP File Name(tmpnam) : %s\n", fname);
	
	
	
	return 0;
}
