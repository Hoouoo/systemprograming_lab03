#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	char * const argv[] = {"ls", "-l", (char *) 0};
	printf("executing execv.\n");
	execv("/bin/ls", argv);
	perror("execv failed to run ls");
	exit(1);
}
