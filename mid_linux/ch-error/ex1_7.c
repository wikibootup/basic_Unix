#include <stdio.h>

int main(int argc, char *argv[])
{
	int n;
	extern char *optarg;
	extern int optind;

	printf("Current Optind : %d\n", optind);
	while((n = getopt(argc, argv, "agc:")) != -1) {
		switch(n) {
			case 'a' :
				printf("Option : a\n");
				break;

			case 'b' :
				printf("Option : b\n");
				break;

			case 'c' :
				printf("Option : c\n");
				break;
		}
		printf("Next Optind : %d\n", optind);
	}
	return 0;
}
