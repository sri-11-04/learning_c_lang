/* 
🟢 Challenge 3 — Copy File Contents

Task:

Open output.txt (created in Challenge 1).

Create a new file called copy.txt.

Copy the contents of output.txt into copy.txt.

Print a success message after copying.

Requirements:

Use fopen in "r" mode for reading and "w" mode for writing.

Read using either fgetc (character by character) or fgets (line by line).

Handle error cases if either file cannot be opened.

Extra:

    Display how many characters were copied in total.
*/

#include <stdio.h>
#include <string.h>

#define READ_FILE "./output.txt"
#define WRITE_CHAR_FILE "./copy_char.txt"
#define WRITE_LINE_FILE "./copy_line.txt"
#define MAX_SIZE 100

static void using_fgets_and_fputs(int *count,FILE *read_file,FILE *write_file);
static void using_fgetc_and_fputc(int *count,FILE *read_file,FILE *write_file);

int main(void){
    FILE *file_read_s = fopen(READ_FILE,"r"),*file_write_s = fopen(WRITE_LINE_FILE,"w"),
        *file_read_c = fopen(READ_FILE,"r"), *file_write_c = fopen(WRITE_CHAR_FILE,"w");
    int total_char_s = 0,total_char_c=0;
    
    if (!(file_read_c || file_read_s)){
        printf("Complete your challenge 1 before proceeding here\n");
        return 1;
    }else if(!(file_write_c || file_write_s)){
        printf("Error while creating the file %s, %s\n",WRITE_CHAR_FILE,WRITE_LINE_FILE);
        return 1;
    }

    using_fgets_and_fputs(&total_char_s,file_read_s,file_write_s);
    using_fgetc_and_fputc(&total_char_c,file_read_c,file_write_c);

    printf("Total count char_by_char: %d, line_by_line: %d\n",total_char_c,total_char_s);
    return 0;
}


static void using_fgets_and_fputs(int *count,FILE *read_file,FILE *write_file){
    char string[MAX_SIZE];

    while((fgets(string,MAX_SIZE,read_file) != NULL)){
        fputs(string,write_file);
        *count+=strlen(string);
    }
    printf("Success coping contents from %s to %s through fgets and fputs\n",READ_FILE,WRITE_LINE_FILE);
    fclose(read_file);
    fclose(write_file);
}

static void using_fgetc_and_fputc(int *count,FILE *read_file,FILE *write_file){
    char c;
    while((c = fgetc(read_file)) != EOF){
        fputc(c,write_file);
        *count = *count+1;
    }
    printf("Success coping contents from %s to %s through fgetc and fputc\n",READ_FILE,WRITE_CHAR_FILE);
    fclose(read_file);
    fclose(write_file);
}