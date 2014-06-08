#include <stdio.h>

int main(int argc, char *argv[])
{
	int n;
	extern char *optarg;
	extern int optind;

	printf("Current Optind : %d\n", optind);
	
	while( (n = getopt(argc, argv, "l") ) != -1) {
		switch(n) {
			case 'l':
				printf("Option : l\n");
				break;
		}
		printf("Next Optind : %d\n", optind);
	}
	return 0;
}

