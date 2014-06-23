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

void ReArrange_argv(int argc, char *argv[]);

void Getopt(int argc, char *argv[], int *flag_v, int *possibilityOfSuccess);

void Fork_n_Exec_n_Rand(int number_of_processes, int possibilityOfSuccess,
	int flag_v, int *fd, char *buf);

const int maxMemSize = 5;
char strTmp[3];

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

	//for pipe()
	int fd[2];
	char buf[5];
//	char strTemp[3];	it is changed to global variable

	if(pipe(fd) == -1)
	{
		perror("pipe");
		exit(1);
	}

//
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
	sprintf(strTmp, "%d", possibilityOfSuccess);

	Fork_n_Exec_n_Rand(number_of_processes, possibilityOfSuccess, 
		flag_v, fd, buf);


		read(fd[0], buf, 5);

	printf("ddasdfasdf\n");
	for(i=0; i<5 ; i++)
	{
	
	//this case is success or failure, so the process is generated
		if(buf[i])
		{
			if(buf[i] == '0'+1)
					percentageOfSuccess += 1;
			else if(buf[i] == '0'+0)
					percentageOfFailure += 1;
		}
	}

	i =0;

	percentageOfSuccess = 
		(percentageOfSuccess / (percentageOfSuccess + percentageOfFailure)) *100;

	percentageOfFailure = 100- percentageOfSuccess;

	printf("\n\n");
	printf("Created %d processes\n", number_of_processes);
	printf("Success - %f%%\n", percentageOfSuccess);
	printf("Failure - %f%%\n", percentageOfFailure);

	close(fd[1]);
	close(fd[0]);

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
	int flag_v, int *fd, char *buf)
{
	//for rand()
	int randVal =0;
	
	//for fork()
	int status;
	pid_t pid;
	int memSize =0;

	while(number_of_processes >0)
	{	
		switch(pid = fork() ) 
		{
			case -1 : /* fork failed */
				perror("fork");
					exit(1);
					break;
			case 0 : /* child process */
				if(flag_v == 1)
				{
					if(execlp("./gambler", "./gambler", "-p", strTmp, "-v" , &fd,
							  (char*)NULL) == -1) {
					perror("execlp");
					exit(1);
					}
				}	
				if(flag_v == 0)
				{
					if(execlp("./gambler", "./gambler", "-p", strTmp, &fd,
								(char*)NULL) == -1) {
					perror("execlp");
					exit(1);
					}
				}	
					break;
				default : /* parent process */
					while(wait(&status) != pid)
						continue;
					break;
		}			
		number_of_processes--;
	
	}
}


