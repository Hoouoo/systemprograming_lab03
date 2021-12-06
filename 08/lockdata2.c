#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define THIS_PROCESS 2
#define THAT_PROCESS 1

int main()
{
	int fd;
	struct flock testlock;
	int len;
	char buf[20];

	/* 읽기 잠금의 인자 지정 */
	testlock.l_type = F_RDLCK;
	testlock.l_whence = SEEK_SET;
	testlock.l_start = 0;
	testlock.l_len = 0;

	/* open file */
	fd = open ("testlock", O_RDWR);
	if (fcntl (fd, F_SETLKW, &testlock) == -1) 
	{
		fprintf (stderr, "process %d: lock failed", THIS_PROCESS);
		exit (1);
	}

	printf ("process %d: locked successfully\n", THIS_PROCESS);
	len = read (fd, buf, 20);
	printf ("process %d: read \"%s\" from testlock\n", THIS_PROCESS, buf);
	printf ("process %d: unlocking\n",
	THIS_PROCESS);
}
