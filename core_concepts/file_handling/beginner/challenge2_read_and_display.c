/* 
🟢 Challenge 2 — Read and Display a File

Task:

    Open the file output.txt (the one you created in Challenge 1).

    Read its content line by line.

    Print each line on the screen.

    Close the file when done.

Requirements:

    Use fopen with "r" mode.

    Use either fgets or fgetc for reading.

    Handle the case where the file doesn’t exist (e.g., if the user didn’t complete Challenge 1).

Extra:

    Display line numbers when printing (e.g., Line 1: ...).
*/


#include <stdio.h>
#include <string.h>

#define FILE_NAME "./output.txt"
#define MAX_CHAR 100

int main(void){
    FILE *file = fopen(FILE_NAME,"r");
    char lines[MAX_CHAR];
    int line = 1;

    if (file == NULL){
        printf("Please complete the challenge 1 before proceeding to challenge 2\n");
        return 1;
    }

    while(fgets(lines,MAX_CHAR,file) != NULL){
        printf("Line %d: %s",line++,lines);
        if (lines[strlen(lines)-1]!='\n') putchar('\n');
    }

    fclose(file);
    return 0;
}