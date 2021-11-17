#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <dirent.h>

int main(int argc, char *argv[]){
	int fd; //파일 디스크립터
	char buf[512];
   	 //인자가 정상 전달되었는지 체크
	if(argc < 3){
		printf("Usage : file_dir [f or d] [name]\n");
		exit(1);
	}
	if(!strcmp(argv[1], "f")){
		printf("file create or made\n");
		if((fd = open(argv[2], O_RDWR|O_CREAT, 0644)) == -1){
			perror("open");
			exit(1);
		}
        	printf("open file : %s\n", argv[2]);
	}
    
	if(!strcmp(argv[1], "d")){
		printf("dir create or chack\n");
		mkdir(argv[2], 0644);
		printf("make dir : %s\n", argv[2]);
	}
	return 0;
}
