#include <stdio.h>
#include <locale.h>


// Use printf to print a number with commas.
// http://stackoverflow.com/questions/1449805/how-to-format-a-number-from-1123456789-to-1-123-456-789-in-c
int main(void) {
    setlocale(LC_NUMERIC, "");
    printf("%'d\n", 12348444);  // As noted, this might not be widely supported.
    return 0;
}
