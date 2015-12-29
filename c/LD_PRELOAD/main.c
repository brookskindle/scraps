#include <stdio.h>
#include <string.h>

int main(void) {
    char s1[] = "my first string",
         s2[] = "my second string";
    int retval = 0;

    printf("String 1: %s\nString 2: %s\n", s1, s2);
    printf("\nResult:\n===============================\n");
    if(!strcmp(s1, s2)) { // s1 and s2 somehow match
        printf("It's a match!\n");
    }
    else {
        printf("Strings do not match\n");
        retval = 1;
    }
    return retval;
}
