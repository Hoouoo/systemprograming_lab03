/*
DEU SystemProgramming_lab03

Team : HOHO
author : 박성호, 고강호

*/

// 헤더파일 정의
#include <stdio.h>
#include <stdlib.h>
// POSIX 운영체제 API에 대한 액세스를 제공하는 헤더파일이다.
#include <unistd.h>
#include <string.h>
// 함수를 통해 시스템 logger에게 메시지를 보낸다.
#include <syslog.h>
// 인터럽트 신호처리를 위해 사용되는 헤더파일이다.
#include <signal.h>
#include <sys/resource.h>
// 파일 처리에 사용되는 헤더파일
#include <fcntl.h>
// 시스템 코드에 사용되는 데이터 형식을 정의한다.
#include <sys/types.h>
// opendir과 같은 디렉토리 관련 헤더파일
#include <dirent.h>
#include <sys/stat.h>
// 시그널로부터 이전 상태 복귀
#include <setjmp.h>

void SIGINT_handler(int signo, pid_t pid);
void SIGTSTP_handler(int signo, pid_t pid);
int main(){
	signal(SIGINT, SIGINT_handler);  // 인터럽트 시그널
	signal(SIGTSTP, 







