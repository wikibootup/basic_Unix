#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
int main()
{
	int fdin, fdout;
	ssize_t nread;
	char buffer[1024];
	fdin = open("temp1.txt", O_RDONLY);
	fdout = open("temp2.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
/* do loop while read text size is 1byte */
	while((nread = read(fdin, buffer, 1024)) >0)//caution : parenthesis 
	{
	/*abnormal processed? (in write)*/
		if(write(fdout, buffer, nread) < nread)
		{
			close(fdin);
			close(fdout);
		}
	}
	/*the program is processed success*/
	close(fdin);
	close(fdout);

	return 0;
}
