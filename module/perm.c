void print_long(mode_t st_mode)
{
	unsigned long perm;

	perm = (st_mode && 0x1f);//rwxrwxrwx=9bit

	if(perm & S_IRUSR)
		printf("r");
	else
		printf("-");
	if(perm & S_IWUSR)
		printf("w");
	else
		printf("-");
	if(perm & S_IXUSR)
		printf("x");
	else
		printf("-");

	if(perm & S_IRGRP)
		printf("r");
	else
		printf("-");
	if(perm & S_IWGRP)
		printf("w");
	else
		printf("-");
	if(perm & S_IXGRP)
		printf("x");
	else
		printf("-");
	if(perm & S_IROTH)
		printf("r");
	else
		printf("-");
	if(perm & S_IWOTH)
		printf("w");
	else
		printf("-");
	if(perm & S_IXOTH)
		printf("x");
	else
		printf("-");


}
