#include <stdio.h>

int main()
{
	FILE *fp;

	fputs("unix system", fp);
	
	fclose(fp);

	return 0;
}
