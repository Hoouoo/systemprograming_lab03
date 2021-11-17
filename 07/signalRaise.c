#include <stdio.h>
#include <signal.h>

int main()
{
	int a, b;
	a = 10;
	b = 0;
	if (b == 0)	raise(SIGFPE);
	a = a / b;
}
