#include <stdio.h>

int main(int argc, char *argv[])
{
	int n;
	extern char *optarg;
	extern int optind;

//	printf("Current Optind : %d\n", optind);
	
	while( (n = getopt(argc, argv, "ahu:") ) != -1) {
		switch(n) {
			case 'a':
//				printf("Option : l\n");
					printf("Welcome to Unix System Programming World!!!\n");
				break;
			case 'u':
					printf("Nice to meet %s\n", argv[2]);
					break;
			case 'h':
					printf("available option : [a], [u] <PAR>, [h]\n");
					break;
		}
//		printf("Next Optind : %d\n", optind);
	}
	return 0;
}

