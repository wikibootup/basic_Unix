#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

void print_mode(mode_t st_mode);

struct stat buf;//file info here

int main(int argc, char *argv[])
{
///////////////getopt///////////////
	int n;
	extern char *optarg;
	extern int optind;
////////////////////////////////////

////////////////////////////////////
	struct stat buf;
//////////////getopt////////////////
//	printf("Current Optind : %d\n", optind);
	
	while( (n = getopt(argc, argv, "l") ) != -1)
	{
			if(n == 'l')
			{	
				//read st_mode
//				printf("Option : l\n");
				stat(argv[2], &buf);
				print_mode(buf.st_mode);


//	printf("Inode	= %d\n",	(int)buf.st_ino);
//	printf("Mode	= %o\n",	(unsigned int)buf.st_mode);
	printf(" %o",	(unsigned int)buf.st_nlink);
	printf(" %d",	(int)buf.st_uid);
	printf(" %d",	(int)buf.st_gid);
	printf(" %d",	(int)buf.st_size);
//	printf("Atime	= %d\n",	(int)buf.st_atime);
	printf(" %d",	(int)buf.st_mtime);
//	printf("Ctime	= %d\n",	(int)buf.st_ctime);
//	printf(" %d\n",	(int)buf.st_blksize);
	printf(" %d",	(int)buf.st_blocks);
	printf(" %s\n", argv[2]);

				break;
			}
	}
/////////////////////////////////////
	return 0;
}


void print_mode(mode_t st_mode)
{
	unsigned long perm;

//////////////permission/////////////////////
//	perm = (st_mode && 0x1f);//rwxrwxrwx=9bit
	if( (st_mode & S_IFMT) == S_IFDIR)
		printf("d");
	else if( (st_mode & S_IFMT) == S_IFREG)
		printf("-");

	if(st_mode & S_IRUSR)
		printf("r");
	else
		printf("-");
	if(st_mode & S_IWUSR)
		printf("w");
	else
		printf("-");
	if(st_mode & S_IXUSR)
		printf("x");
	else
		printf("-");

	if(st_mode & S_IRGRP)
		printf("r");
	else
		printf("-");
	if(st_mode & S_IWGRP)
		printf("w");
	else
		printf("-");
	if(st_mode & S_IXGRP)
		printf("x");
	else
		printf("-");
	if(st_mode & S_IROTH)
		printf("r");
	else
		printf("-");
	if(st_mode & S_IWOTH)
		printf("w");
	else
		printf("-");
	if(st_mode & S_IXOTH)
		printf("x");
	else
		printf("-");
}

