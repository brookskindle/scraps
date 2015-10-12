/* Test to figure out the size of an enum */

#include <stdio.h>

typedef enum test {
    One, Two, Three
}Test;

int main(void) {
    printf("Size of double in bytes: %ld\n", sizeof(double));
    printf("Size of float in bytes: %ld\n", sizeof(float));
    printf("Size of int in bytes: %ld\n", sizeof(int));
    printf("Size of char in bytes: %ld\n", sizeof(char));
    printf("Size of enums in bytes: %ld\n", sizeof(Test));
    return 0;
}
