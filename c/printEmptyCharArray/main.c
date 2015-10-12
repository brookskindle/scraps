#include <stdio.h>

int main(void) {
	char buf[1024];
	char buf2[] = "hello world";
	char buf3[] = "this_string_should_never_be_printed";
	char *p = buf;
	buf2[sizeof(buf2) / sizeof(char) - 1] = '!'; //remove null-character

//	while(p - buf < sizeof(buf) / sizeof(char)) {
//	}//end while

	printf("printing a non-allocated buffer: ");
	printf("%s\n", buf);
	printf("printing a non null-terminated buffer: ");
	printf("%s\n", buf2);

	return 0;
}//end main
