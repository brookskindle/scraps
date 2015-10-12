#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(void) {
	char *line = 0;
	int n = 0;
	getline(&line, &n, stdin);
	printf("%s", line);
	printf("[proc2] pid=%d, ppid=%d\n", getpid(), getppid());
	return 0;
}
