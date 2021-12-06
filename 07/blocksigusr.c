#include <stdio.h>
#include <signal.h>
#include <unistd.h>
void handler1(int);
void handler2(int);
sigset_t set;
int main()
{
	struct sigaction act;
	/* Set up signal set with just SIGUSR1. */
	sigemptyset(&set);
	sigaddset(&set, SIGUSR1);
	/* Trap SIGUSR1. */
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	act.sa_handler = handler1;
	sigaction(SIGUSR1, &act, NULL);
	/* Trap SIGUSR2 - just change handler in action. */
	act.sa_handler = handler2;
	sigaction(SIGUSR2, &act, NULL);
	/* Block SIGUSR1 */
	sigprocmask(SIG_BLOCK, &set, NULL);
	/* We will get a USR2 first because USR1 is blocked. */
	while(1) 
	{
		pause();
		sigprocmask(SIG_UNBLOCK, &set, NULL);
		/* Unblock USR1 here. */
	}
}
void handler1(int sig)
{
	printf("Got a SIGUSR1 signal\n");
}
void handler2(int sig)
{
	printf("Got a SIGUSR2 signal\n");
}
