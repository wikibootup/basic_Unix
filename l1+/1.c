#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int n;
	extern char *optarg;
	extern int optind;

		while( (n = getopt(argc, argv, "au:h") ) != -1) {
			switch(n) {
				case 'a':
					printf("Welcome to Unix Programming world!!!\n");
					break;
				case 'u':
					printf("Nice to meet %s\n", argv[2]);
					break;
				case 'h':
					printf("valid Option:[l][u][h]");
					break;

			}

		}
	return 0;
}

