#include <stdio.h>
#include <termios.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#define PASSWORDSIZE 12
int main(void)
{
	int fd,type_cnt=0;
	int start_time, end_time;
	double elapsed, type_speed;
	int nread, cnt=0, errcnt=0;
	char ch, text[] = "The magic thing is that you can change it.";
	struct termios init_attr, new_attr;

	fd = open(ttyname(fileno(stdin)), O_RDWR);
 	tcgetattr(fd, &init_attr);
	new_attr = init_attr;
	new_attr.c_lflag &= ~ICANON;
	new_attr.c_lflag &= ~ECHO; /* ~(ECHO | ECHOE | ECHOK | ECHONL); */
	new_attr.c_cc[VMIN] = 1;
	new_attr.c_cc[VTIME] = 0;
	if (tcsetattr(fd, TCSANOW, &new_attr) != 0) {
		fprintf(stderr, "터미널 속성을 설정할 수 없음.\n");
	}
	printf("다음 문장을 그대로 입력하세요.\n%s\n", text);

	start_time = time(NULL);
	while ((nread=read(fd, &ch, 1)) > 0 && ch != '\n') {
		if (ch == text[cnt++])
			write(fd, &ch, 1);
		else {
			write(fd, "*", 1);
			errcnt++;
		}
		type_cnt ++;
		}
	end_time = time(NULL);
	printf("\n타이핑 오류의 횟수는 %d\n", errcnt);
	tcsetattr(fd, TCSANOW, &init_attr);
	close(fd);
	elapsed = (double)(end_time - start_time);
	type_speed = (type_cnt/elapsed)*60;
	printf("당신의 타자 속도는 : %4.2f", type_speed);
}
