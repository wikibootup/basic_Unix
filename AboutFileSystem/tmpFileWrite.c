//for fwrite(3), fopen(3)
#include <stdio.h>
#include <string.h>
//for mktemp(3), exit()
#include <stdlib.h>

//BUFSIZ if defined in stdio.h
int main(void)
{
	char *fname;
	char template[32];

	FILE *fp;
	char buf[BUFSIZ];
	int n;

	fname = tmpnam(NULL);
	printf("Temprorary file name is ' %s\n '", fname);

	if( (fp = fopen(fname, "w")) == NULL ){
		perror("fopen : temporary file");
		exit(1);
	}
	//fp points to temporary file
	fputs("Mr.Kim", fp);
	fputs("20021224", fp);	
	
	fclose(fp);
	
	return 0;
}
