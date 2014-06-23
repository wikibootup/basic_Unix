#include <stdio.h>
#include <string.h>
#include <time.h>
//for atoi(), pipe()
#include <stdlib.h>
//for fork(), exec()
#include <sys/types.h>
#include <unistd.h>
//for strlen()
#include <string.h>
#include <signal.h>

void Getopt(int argc, char *argv[], int *flag_v, int *possibilityOfSuccess);

void Fork_n_Exec_n_Rand(int number_of_processes, int possibilityOfSuccess,
	int flag_v, int *fd, char *buf);

const int maxMemSize = 10;
char strTmp[3];
int *fd;

int main(int argc, char *argv[])
{
	int n;
	extern char *optarg;
	extern int optind;


	int randVal =0;
	int number_of_processes =0;
	int possibilityOfSuccess =0;
	double percentageOfSuccess =0;
	double percentageOfFailure =0;	
	int flag_v =0;
	char strPossibilityOfSuccess[3];

	int i;

	//for pipe()
	char buf[10];

	Getopt(argc, argv, &flag_v, &possibilityOfSuccess);
	//
	Fork_n_Exec_n_Rand(number_of_processes, possibilityOfSuccess, 
		flag_v, fd, buf);

//	close(fd[1]);
//	close(fd[0]);
	exit(1);
	return 0;
}



void Getopt(int argc, char *argv[], int *flag_v, int *possibilityOfSuccess)
{
	int n;
	while( (n = getopt(argc, argv, "p:v:") ) != -1) {
		switch(n) {
			case 'p':
				*possibilityOfSuccess = atoi(optarg);
				break;
			case 'v':
				*flag_v = 1;
				fd = (int*)optarg;
				break;
		}
	}	
}

void Fork_n_Exec_n_Rand(int number_of_processes, int possibilityOfSuccess, 
	int flag_v, int *fd, char *buf)
{
	//for rand()
	int randVal =0;
	
	//for fork()
	int status;
	pid_t pid;
	int memSize =0;
		
				srand(time(NULL)*getpid());
				randVal = rand() % 100 + 1;
								
				if( (randVal >100) ||  (randVal <0) )
				{
					fprintf(stderr, "out of range of percentage. it should be 0~100\n");
					exit(1);
				}	
					if(randVal < possibilityOfSuccess)
					{
						write(fd[1], "1", 1);
						memSize++;
						if(memSize > maxMemSize)
						{
							fprintf(stderr, "memory size can't size up more than 5\n");
							exit(1);
						}
						if(flag_v == 1)	
							{						
								printf("PID %d returned success\n", getpid());
								exit(1);
						}
	
					}	
					else
					{
						write(fd[1], "0", 1);
						memSize++;
						if(memSize >maxMemSize)
						{
							fprintf(stderr, "memory size can't size up more than 5\n");
							exit(1);
						}
						if(flag_v == 1)
						{
							printf("PID %d returned failure\n", getpid());
							exit(1);
						}

					}
			exit(1);//all jobs are done, then exit child process, that is gambler	
}


