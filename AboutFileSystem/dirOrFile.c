#include <stdio.h>
//for constant about file kind
#include <sys/stat.h>
#include <sys/types.h>

int main(void) {
	struct stat buf;
	int kind;
	stat("./", &buf);:
