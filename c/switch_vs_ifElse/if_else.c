/**
 * @brief Tests the efficiency of an if-else statement vs a switch statement
 */
#include <stdio.h>

int main(void) {
	int i;
	printf("Enter an integer for i[0, -1, 1]: ");
	scanf("%d", &i);
	if(i == 0) {
		printf("you printed 0\n");
	}
	else if(i == -1) {
		printf("-1, that's not real!\n");
	}
	else if(i == 1) {
		printf("the only one\n");
	}
	else {
		printf("no idea what that is..\n");
	}
	return 0;
}
