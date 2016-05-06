/*
Ryan Bambrough, section 1
Cheng-Hsiang Hsu, section 1
*/

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

int count = 0;

//handler for divide by zero
void handler_divide_by_zero(int sig){
	printf("A divide by zero error has occured.");
	printf("\nNumber of successful divisions: %d\n", count);
	exit(0);
}

//handler for interrupt 
void handler_int(int sig){
	printf("\nNumber of successful divisions: %d\n", count);
	exit(0);
}

int main(){

	struct sigaction sa1;

    sa1.sa_handler = handler_divide_by_zero;
    sigemptyset(&sa1.sa_mask);
    sa1.sa_flags = SA_RESTART;
   
    //detect divide_by_zero signal
    if (sigaction(SIGFPE, &sa1, NULL) != 0){
		printf("Error when setting up sigaction() for SIGFPE.\n");
	}

	sa1.sa_handler = handler_int;

	//detect the interrupt
    if (sigaction(SIGINT, &sa1, NULL) != 0){
		printf("Error when setting up sigaction() for SIGFPE.\n");
	}

	//infinite loop
	while (1) {
        int num1, num2;
        char input[100];

		//get input from user
        printf("Enter first integer: ");
		if (fgets(input, 100, stdin) != NULL) {    
			num1 = atoi(input);          
		}
        
		printf("Enter second integer: ");
        
		if (fgets(input, 100, stdin) != NULL) {
        	num2 = atoi(input);
        }

        int quotient = num1 / num2;
		int remainder = num1%num2;
		count++;
		printf("%d / %d is %d with a remainder of %d\n", num1, num2, quotient, remainder);
    }

	return 0;
}