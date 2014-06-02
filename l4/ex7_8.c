#include <sys/ucontext.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

void handler(int signo, siginfo_t *sf, ucontext_t *uc);

int main(void) {
	struct sigaction act;
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = (void (*)(int, siginfo_t *, void *))handler;
	sigemptyset(&act.sa_mask);
	if(sigaction(SIGUSR1, &act, (struct sigaction *)NULL) < 0) {
		perror("sigaction");
		exit(1);
	}
	
	pause();
	return 0;
}


void handler(int signo, siginfo_t *sf, ucontext_t *uc)
{
	psiginfo(sf, "Received Signal:");
	printf("si_code : %d\n", sf ->si_code);
}

