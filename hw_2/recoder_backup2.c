#include <stdio.h>
#include <time.h>
//for atoi()
#include <stdlib.h>
//for fork(), exec()
#include <sys/types.h>
#include <unistd.h>
//for memory mapping
#include <sys/mman.h>
#include <fcntl.h>


void ReArrange_argv(int argc, char *argv[]);

void Getopt(int argc, char *argv[], int *flag_v, int *possibilityOfSuccess);

void Fork_n_Exec_n_Rand(int number_of_processes, int possibilityOfSuccess,
	int flag_v, caddr_t addr);

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

	int i;

	//for memory mapping
	int fd;
	caddr_t addr;
	struct stat statbuf;
//
	if((fd = open("mmap.dat", O_CREAT | O_RDWR | O_TRUNC, 0644)) == -1)
	{
		perror("open");
		exit(1);
	}
	
	if(stat("mmap.dat", &statbuf) == -1)
	{
		perror("stat");
		exit(1);
	}
	
	addr = mmap(NULL, 40, PROT_READ | PROT_WRITE,
					MAP_SHARED, fd, (off_t)0);
//
	if(addr == MAP_FAILED)
	{
		perror("mmap");
		exit(1);
	}

	//initialize addr[0..4] to -1
	//that means the process  doesn't worked
/*
	addr[0] = -1;
	addr[1] = -1;
	addr[2] = -1;
	addr[3] = -1;
	addr[4] = -1;
*/
	addr[0] = '1';

	printf("%s\n", addr);
//re-arrange argv by getopt()		
	ReArrange_argv(argc, argv);

	for(i = 0 ; argv[i] ; i++)
	;
	//argv is re-arranged by getopt()
	//last argument is non-option value.
	//that is number_of_process
	//exception process about range of number of processes
	if((atoi(argv[i-1]) > 5) || (atoi(argv[i-1]) <= 0) )
	{
		fprintf(stderr, "range of 'number of processes' should be 1~5\n");
		exit(1);
	}
	else	//save the number of processes
		number_of_processes = atoi(argv[i-1]);

	//optind is needed to set '1', because when getopt() is executed
	//optind is moved to last argument number+1
	optind =1;


	Getopt(argc, argv, &flag_v, &possibilityOfSuccess);
	//

	Fork_n_Exec_n_Rand(number_of_processes, possibilityOfSuccess, 
		flag_v, addr);
/*
	for(i=0 ; i<5 ; i++)
	{
		//this case is success or failure, so the process is generated
		if(isSucceed[i] ==1)
				percentageOfSuccess += 1;
		else if(isSucceed[i] == 0)
				percentageOfFailure += 1;
	}

	percentageOfSuccess = 
		(percentageOfSuccess / (percentageOfSuccess + percentageOfFailure)) *100;

	percentageOfFailure = 100- percentageOfSuccess;
*/	
	printf("\n\n");
	printf("Created %d processes\n", number_of_processes);
	printf("Success - %f%%\n", percentageOfSuccess);
	printf("Failure - %f%%\n", percentageOfFailure);
//	printf("%d %d %d %d %d", addr[0],  addr[1], addr[2]
//					addr[3], addr[4]);
		
	close(fd);
	if(munmap(addr, 40) == -1)
	{
		perror("munmap");
		exit(1);
	}

	return 0;
}



void ReArrange_argv(int argc, char *argv[])
{
	int n;
//re-arrange argv by getopt()	
	while( (n = getopt(argc, argv, "p:v:") ) != -1) 
	{
		switch(n) {
			case 'p':	break;
			case 'v': break;
			default :
				fprintf(stderr, "only -p or -v options are available.\n");
				fprintf(stderr, "Or last argument should be non-option value.\n");

				exit(1);	
		}
	}
}


void Getopt(int argc, char *argv[], int *flag_v, int *possibilityOfSuccess)
{
	int n;
	while( (n = getopt(argc, argv, "p:v") ) != -1) {
		switch(n) {
			case 'p':
				*possibilityOfSuccess = atoi(optarg);
				break;
			case 'v':
				*flag_v = 1;
				break;
		}
	}
	
}


void Fork_n_Exec_n_Rand(int number_of_processes, int possibilityOfSuccess, 
	int flag_v, caddr_t addr)
{
	//for rand()
	int randVal =0;
	
	//for fork()
	int status;
	pid_t pid;

	while(number_of_processes >0)
	{	
		switch(pid = fork() ) 
		{
			case -1 : /* fork failed */
				perror("fork");
					exit(1);
					break;
			case 0 : /* child process */
				srand(time(NULL)*getpid());
				randVal = rand() % 100 + 1;
								
				if( (randVal >100) ||  (randVal <0) )
				{
					fprintf(stderr, "out of range of percentage. it should be 0~100\n");
					exit(1);
				}	
					if(randVal < possibilityOfSuccess)
					{
						addr[number_of_processes-1] = 1;
						if(flag_v == 1)								
							printf("PID %d returned success\n", getpid());
					}
					else
					{
						addr[number_of_processes-1] = 0;
						if(flag_v == 1)
							printf("PID %d returned failure\n", getpid());
					}
					exit(2);
					break;
				default : /* parent process */
					while(wait(&status) != pid)
						continue;
					break;
				}			
	
		number_of_processes--;
	}


}


