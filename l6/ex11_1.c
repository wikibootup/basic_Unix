#include <netdb.h>
#include <sys/socket.h>
#include <stdio.h>

int main()
{
	struct hostent *hent;
	sethostent(0);
	while((hent = gethostent()) != NULL)
		printf("Name = %s\n", hent ->h_name);

	endhostent();
	return 0;
}
