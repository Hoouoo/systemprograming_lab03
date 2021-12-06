#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int printpos (const char *string, int filedes);
void fatal(char *error_name);

int main(int argc, char *argv[])
{
	int fd;
	pid_t pid;
	char buf[10];
	
	if (argc < 2){
		fprintf(stderr, "Usage: %s [file_name]\n", argv[0]); 
		exit(1); 
	}
	
	if ((fd = open (argv[1], O_RDONLY)) == -1)	fatal ("open failed");
	
	read (fd, buf, 10);
	printpos("Before fork", fd);

	switch(pid = fork()) {
	case -1:
		fatal ("folk failed");
		break;
	case 0:
		printpos ("Child before read", fd);
		read (fd, buf, 10);
		printpos ("Child after read", fd);
		break;
	default:
		wait ((int *) 0);
		printpos ("Parent after wait", fd);
	}
}

int printpos (const char *string, int filedes)
{
	off_t pos;
	if ((pos = lseek (filedes, 0, SEEK_CUR)) == -1)	fatal ("lseek failed");
	printf ("%s:%ld\n", string, pos);
}

void fatal(char *error_name)
{
    perror(error_name);
    exit(1);
}
