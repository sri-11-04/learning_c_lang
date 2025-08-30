#include <stdio.h>

int main(void){
    printf("Enter something... ");
    char c = getchar(); // returns a int of the char (only first char)
    putchar(c); // can only prints a char on the terminal
    putchar('\n');
    return 0;
}