/**
 * @brief Tests the efficiency of an if-else statement vs a switch statement
 */
#include <stdio.h>

int main(void) {
	int i;
	printf("Enter an integer for i[0, -1, 1]: ");
	scanf("%d", &i);
	switch(i) {
		case 0:
			printf("you printed 0\n");
			break;
		case -1:
			printf("-1, that's not real!\n");
			break;
		case 1:
			printf("the only one\n");
			break;
		default:
			printf("no idea what that is..\n");
			break;
	}
	return 0;
}
