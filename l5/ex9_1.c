#include <stdlib.h>
#include <stdio.h>

int main(void) {
		FILE *fp;
		int a;
		char buf[256];

		if((fp = popen("wc -l", "w"))==NULL) {
			fprintf(stderr, "popen failed\n");
			exit(1);
		}

		for(a=0 ; a <100 ; a++)
			fprintf(fp, "test line\n");

		pclose(fp);

		if((fp = popen("date", "r")) == NULL) {
			fprintf(stderr, "popen failed\n");
			exit(1);
		}

		if(fgets(buf, sizeof(buf), fp) == NULL) {
			fprintf(stderr, "No data from pipe!\n");
			exit(1);

		}

		printf("line : %s\n", buf);
		pclose(fp);

		return 0;
}
