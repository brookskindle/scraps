#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(void) {
	printf("[proc1] pid=%d, ppid=%d\n", getpid(), getppid());
	return 0;
}
