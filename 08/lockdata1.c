#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#define THIS_PROCESS 1
#define THAT_PROCESS 2
int main()
{
	int fd;
	struct flock testlock;
	char buf[20];
	
	/* 쓰기 잠금의 인자 지정 */
	testlock.l_type = F_WRLCK;
	testlock.l_whence = SEEK_SET;
	testlock.l_start = 0;
	testlock.l_len = 0;
	
	/* open file */
	fd = open ("testlock", O_RDWR | O_CREAT,0666);
	
	if (fcntl (fd, F_SETLKW, &testlock) == -1) 
	{
		fprintf(stderr, "process %d: lock failed", THIS_PROCESS);
		exit (1);
	}
	printf ("process %d: locked successfully\n",THIS_PROCESS);
	sprintf(buf,"Hello, process %d", THAT_PROCESS);
	write (fd, buf, 17);
	printf ("process %d: wrote \"%s\" to testlock\n", THIS_PROCESS, buf);
	sleep (5);
	printf ("process %d: unlocking\n",THIS_PROCESS);
}
