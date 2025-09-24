/* 
🟢 Challenge 4 — Append Data to an Existing File

Task:

    Open output.txt (created in Challenge 1).

    Ask the user to enter 3 more lines of text.

    Append these lines at the end of the file without overwriting the existing content.

    Close the file when done.

Requirements:

    Use fopen with "a" mode (append).

    Use fgets + fputs or fprintf for writing.

    Handle error if the file doesn’t exist.

Extra:

    After appending, reopen the file in "r" mode and print the full updated content to confirm.
*/

#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100
#define LINES 3
#define FILE_NAME "./output.txt"

static int get_file_lines(int *line,FILE *file);
static void read_file(FILE *file);

int main(void){
    FILE *file = fopen(FILE_NAME,"a+");
    char lines[MAX_SIZE];
    if (file == NULL){
        printf("Error while openning the file %s\n",FILE_NAME);
        return 1;
    }
    int pre_lines = 0;
    get_file_lines(&pre_lines,file);

    for (int i =pre_lines+1; i<LINES+pre_lines+1;i++){
        printf("Enter line [%d]: ",i);
        fgets(lines,MAX_SIZE,stdin);
        lines[strcspn(lines,"\n")] = '\0';
        fputs(lines,file);
        fputc('\n',file);
    }
    putchar('\n');
    printf("Reading from the file %s\n",FILE_NAME);
    read_file(file);
    fclose(file);
    return 0;
}

static int get_file_lines(int *line,FILE *file){
    char line_content[MAX_SIZE];
    rewind(file);
    while (fgets(line_content,MAX_SIZE,file) != NULL){
        *line=*line+1;
    }
    return *line;
}

static void read_file(FILE *file){
    char string[MAX_SIZE];
    int line = 1;
    rewind(file);
    while (fgets(string,MAX_SIZE,file) != NULL){
        printf("Line [%d]: %s",line++,string);
        if (string[strlen(string)-1] != '\n') putchar('\n');
    }
}