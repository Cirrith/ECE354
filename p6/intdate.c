/*
Ryan Bambrough, section 1
Cheng-Hsiang Hsu, section 1
*/

#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include<string.h>

int count = 0;

int alarm_time = 3;

//handler that handles both SIGALRM and SIGINT
void handler(int sig)
{
	
	if(sig == SIGALRM)
	{
		time_t curtime;

        time(&curtime);

		printf("current time is %s", ctime(&curtime));
		
		//re-alarm
		alarm(alarm_time);
	}
	
	if(sig == SIGINT)
	{
		count++;
		printf("\nControl+c caught. %d more before program is ended.\n",5-count);
		if(count == 5)
		{
			printf("Final Control+c caught. Exiting.\n");
			exit(0);
		}
	}
}

int main()
{
	printf("Date will be printed every 3 seconds.\n");
	printf("Enter ^C 5 times to end the program:\n");

	struct sigaction sa1;
	memset(&sa1, 0, sizeof(sa1));
    sa1.sa_handler = handler;
    
    sa1.sa_flags = SA_RESTART;
   
    //detect SIGARM 
    if (sigaction(SIGALRM, &sa1, NULL) != 0){
		printf("Error when setting up sigaction() for SIGFPE.\n");
	}
	
	//detect interrupt
	if (sigaction(SIGINT, &sa1, NULL) != 0){
		printf("Error when setting up sigaction() for SIGFPE.\n");
	}
	
	alarm(alarm_time);
	
	while(1)
	{
		
	}
}