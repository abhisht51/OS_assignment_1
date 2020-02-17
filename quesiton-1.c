/*
Name: Abhisht Kumar Singh	
ID: 1810110006
Teammate's name: Isha Tyagi
*/

#include <stdio.h>
#include <unistd.h>
#include<sys/types.h>
#include<stdlib.h>
#define MAX_LINE 80 /* The maximum length command */ 
#include <string.h> 

int spawn(char* program,char** arg_list)
{
	pid_t child_pid;
	child_pid = fork();
	if(child_pid!=0)
		return child_pid;
	else 
	{
		execvp(program,arg_list);
		
		fprintf(stderr,"an error occurred in execvp\n");
		abort();
	}	
}

int main(void)
{
	char *args[MAX_LINE/2 + 1]; /* command line arguments */
	int should_run = 1; /* flag to determine when to exit program */ 
	while (should_run) {
		printf("osh>");
		fflush(stdout);
		gets(*args);
		char *token = strtok(*args, " ");
		char* arg_list[5]; 
		int c=0;
		while(token != NULL)
		{
			arg_list[c++]=token;
			token=strtok(NULL," ");
		}
		arg_list[c]=NULL;
		c=0;
		/*
		while(arg_list[c]!=NULL)
			printf("%s",arg_list[c++]);
		printf("\n");
		*/
		if(strcmp(arg_list[0],"quit")==0) //checks if the first argument is 'exit' and quits the while loop
			{ 
			should_run=0;
			break;
			}
		spawn(arg_list[0],arg_list);
		printf("Done with main program\n");
		/**
		* After reading user input, the steps are:
		* (1) fork a child process using fork()
		* (2) the child process will invoke execvp()
		* (3) if command included &, parent will not invoke wait()	
		* (4) if command is quit, the shell should exit
		*Explain your steps as comments in the code itself.

		*/

	}

return 0;
}
