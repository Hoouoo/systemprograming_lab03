/*fork.c*/
/*fork example*/
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){

    	pid = fork();
    	if (pid == 0){
        	printf("I'm the child process\n");
   	}
   	else if (pid > 0){
		printf("I'm the parent process\n");
        	sleep(3);
   	}
    	else{
        	printf("wait for parent\n");   
    	}
    	return 0;
}
