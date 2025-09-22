/* 
🟢 Challenge 1 — Write a Simple Text File

Task:
    Ask the user to enter 5 lines of text.
    Write each line into a file called output.txt.
    After writing, close the file.

Requirements:
    Use fopen with "w" mode.
    Use either fprintf or fputs to write lines.

Extra:
    Make sure the file is created in the same directory as your program.
*/


#include <stdio.h>
#include <string.h>

#define FILE_NAME "./output.txt"
#define LINE 5

int main(void){
    FILE *file = fopen(FILE_NAME,"w");
    char string[100];

    if (file == NULL) {
        printf("Error in creating a file!\n");
        return 1;
    }
    for (int i = 1;i<=LINE;i++){
        printf("Enter line %d: ",i);
        fgets(string,sizeof(string),stdin);
        string[strcspn(string,'\n')] = '\0'; // * it will slice from 0 to index('\n') and returns its length
        fputs(string,file);
        fputc('\n',file);
    }

    fclose(file);
    return 0;
}

