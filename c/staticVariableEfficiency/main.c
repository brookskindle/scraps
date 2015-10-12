/*
1/24/14
small program to test whether or not using static variables improves
performance vs dynamically allocating memory
*/

#include <stdio.h> //for printf
#include <time.h> //for clock_t, clock(), CLOCKS_PER_SEC
#include <stdlib.h> //for malloc
#include <string.h>

char _global[50];

char *strcpy_static(const char *src);
char *strcpy_global(const char *src);
char *strcpy_dynamic(const char *src);

int main(void) {
    clock_t cycles; //number of clock cycles
    int n = 10000000,
        i = 0;
    char str[] = {"To be or not to be, that is the question."},
         *res = NULL;

    //test global strcpy
    printf("Testing strcpy on a global variable %d times.\n", n);
    cycles = clock(); //start the clock
    for(i = 0; i < n; i++) {
        res = strcpy_global(str);
    }
    cycles = clock() - cycles; //calculate delta cycles
    printf("Ok...%f seconds\n", (float)cycles / CLOCKS_PER_SEC);

    //test static strcpy
    printf("Testing strcpy on a static variable %d times.\n", n);
    cycles = clock(); //start the clock
    for(i = 0; i < n; i++) {
        res = strcpy_static(str);
    }
    cycles = clock() - cycles; //calculate delta cycles
    printf("Ok...%f seconds\n", (float)cycles / CLOCKS_PER_SEC);

    //test dynamic strcpy
    printf("Testing strcpy on a dynamic variable %d times.\n", n);
    cycles = clock(); //start the clock
    for(i = 0; i < n; i++) {
        res = strcpy_dynamic(str);
        free(res);
    }
    cycles = clock() - cycles; //calculate delta cycles
    printf("Ok...%f seconds\n", (float)cycles / CLOCKS_PER_SEC);

    return 0;
}//end main


//copies a string into a statically allocated array and returns the string
char *strcpy_static(const char *src) {
    static char _static[50] = {0};
    strcpy(_static, src);
    return _static;
}


//does the same thing, but uses a global variable
char *strcpy_global(const char *src) {
    strcpy(_global, src);
    return _global;
}


//does the same thing, but dynamically creates memory
char *strcpy_dynamic(const char *src) {
    char *_dynamic = (char *)malloc(sizeof(char) * 50);
    strcpy(_dynamic, src);
    return _dynamic;
}
