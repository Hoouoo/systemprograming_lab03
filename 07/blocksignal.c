#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
	sigset_t set1, set2;
	sigfillset(&set1);
	sigemptyset(&set2);
	
	sigaddset(&set2, SIGINT);
	printf("Critical region start.\n");
	
	sigprocmask(SIG_BLOCK, &set1, NULL);
	
	sleep(5);
	printf("Less critical region start.\n");
	
	sigprocmask(SIG_UNBLOCK, &set2, NULL);
	
	sleep(5);
	printf("Non critical region start.\n");
	
	sigprocmask(SIG_UNBLOCK, &set1, NULL);
	
	sleep(5);
}
