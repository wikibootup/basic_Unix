#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/times.h>

#define CLK_TCK sysconf(_SC_CLK_TCK)

int main(int argc, char *argv[])
{
	int i;
	struct tms mytms;
	clock_t t1, t2;

	if( (t1 = times(NULL)) == -1) {
		perror("times 1");
		exit(1);
	}

	for(i=0 ; i< 999999 ; i++)
		times(NULL);

	if( (t2 = times(&mytms)) == -1) {
		perror("times 2");
		exit(1);
	}

	printf("Real	time : %.2f set\n", (double)(t2-t1)/CLK_TCK);
	printf("User	time : %.2f set\n", (double)(mytms.tms_utime)/CLK_TCK);
	printf("Sys		time : %.2f set\n", (double)(mytms.tms_stime)/CLK_TCK);

	return 0;
}
