#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <stdio.h>

int main(int argc, char *argv[]){

	int fd;
	
	if((fd = open(argv[1], O_RDWR | O_CREAT, 0644)) == -1)
	{
		printf("Could not open %s \n", argv[1]);
		exit(1);
	}else{
		printf("Open %s\n", argv[1]);
	}

	exit(0);
} 
