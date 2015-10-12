#include <string.h>
#include <stdio.h>
void do_strtok(void);
int main(void) {
    char str[] = {"/usr/bin/xchat/what"};
    char str1[] = {"/bob/the/tomato/"};
    char str2[] = {"relative/pathname"};
    char str3[] = {"/"};
    char *token = NULL;

    printf("Tokenizing \"%s\"\n", str);
    token = strtok(str, "/");
    do {
        printf("\t%s", token);
        token = strtok(NULL, "/");
    }while(token);
    printf("\n");

    printf("Tokenizing \"%s\"\n", str1);
    token = strtok(str1, "/");
    do {
        printf("\t%s", token);
        token = strtok(NULL, "/");
    }while(token);
    printf("\n");

    printf("Tokenizing \"%s\"\n", str2);
    token = strtok(str2, "/");
    do {
        printf("\t%s", token);
        token = strtok(NULL, "/");
    }while(token);
    printf("\n");
    
    printf("Tokenizing \"%s\"\n", str3);
    token = strtok(str3, "/");
    do {
        printf("\t%s", token);
        token = strtok(NULL, "/");
    }while(token);
    printf("\n");

	do_strtok();
}


void do_strtok(void) {
	char *line = 0,
		 buf[1024] = {0},
		 delim[15] = {0};
	printf("Enter a line to strtok: ");
	line = gets(buf);
	printf("Now enter a delimeter: ");
	gets(delim);
	if(line == 0 || delim == 0) {
		printf("sorry, but there was an error\n");
		return;
	}
	printf("You chose line=%s and delim=%s\n", line, delim);
	getchar();
	line = strtok(line, delim);
	while(line) {
		printf("strtok yields: %s\n", line);
		line = strtok(0, delim);
		getchar();
	}
	printf("strtok yielded NULL\n");
	getchar();
}//end do_strtok
