#include <stdio.h>

void x(char b[]);
void y(char *b);

int main(void) {
	char *c;
	char buf[] = "asdfasdfasdfasdfasdf";
	int *i;
	float *f;
	double *d;

	printf("pointer sizes: char=%d, int=%d, float=%d, double=%d\n", sizeof(c), sizeof(i), sizeof(f), sizeof(d));

	printf("sizeof buf inside main: %d\n", sizeof(buf));
	x(buf);
	y(buf);

	return 0;
}

void x(char b[]) {
	printf("inside void x(char buf[]); sizeof buf: %d\n", sizeof(b));
}
void y(char *b) {
	printf("inside void y(char *b); sizeof buf: %d\n", sizeof(b));
}
