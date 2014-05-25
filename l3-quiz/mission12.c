#include <stdio.h>
//for atexit(3)
#include <stdlib.h>
//fr waitpid(), fork(2)
#include <sys/types.h>
#include <sys/wait.h>
//for exec series, fork(2), dup(2)
#include <unistd.h>
//for open(2)
#include <sys/stat.h>
#include <fcntl.h>
//for strcmp, strlen
#include <string.h>
//for struct stat
#include <sys/stat.h>
//for calender time
#include <time.h>

void byebye()
{
	printf("byebye~\n");
}

int main(int argc, char *argv[])
{
	atexit(byebye);//message when the program terminates

	int fd, fd1;
	pid_t pid[2];
	//this variable can be modified one or more times. (no char* type) 
	char userInput[BUFSIZ];
	char fileName[BUFSIZ];
//for using to hold the time and date
	struct tm *nowTime;
//for storing the calender time
	time_t t;
//calculates current calender time
	time(&t);
//localizing
	nowTime = localtime(&t);
//set file name
//file name = time when program is executed (2014.xx.xx.log)
	sprintf(fileName, "%d.%d.%d.log", 1900 + nowTime->tm_year, nowTime->tm_mon, nowTime->tm_mday);
	
	fd = open(fileName, O_CREAT | O_TRUNC, 0644);
	close(fd);

	while(1) {
	
		scanf("%s", userInput);
// perform the instruction user insertd before "Quit"
				if(strcmp(userInput, "Quit") == 0) 
					break;					
///////////////////////fork 1//////////////////////////
		switch(pid[0] = fork()) {
			case -1 : //fork failed
				perror("fork");
				exit(1);
				break;
			case 0 :
//child process1
//1. execute the instruction user inserted
					execlp(userInput, userInput, (char*)NULL);
					break;
			default : //parent process
								//1. create child process
								//2. sync processes
								//3. terminate program
				while(waitpid(pid[0], 0, 0) != pid[0] )
					continue;
				break;
		}
/////////////////////////fork 2////////////////////////

		switch(pid[1] = fork()) {
			case -1 : //fork failed
				perror("fork");
				exit(1);
				break;
			case 0 :
//child process2
//1. print the result of execution of the instruction in file
//2. file name = time when program is executed (2014.xx.xx.log)
				close(1);// stdout exit
				fd = open(fileName, O_WRONLY | O_APPEND, 0644);
				execlp(userInput, userInput, (char*)NULL);
				close(fd);	
				break;
			default : 
//parent process
//1. create child process
//2. sync processes
//3. terminate program
				while((waitpid(pid[1], 0, 0)) != pid[1])
					continue;
				break;
		}
//////////////////////////////////////////////////
	}
	exit(0);
	return 0;
}
