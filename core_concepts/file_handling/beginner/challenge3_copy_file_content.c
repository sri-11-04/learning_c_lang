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
*/

#include <stdio.h>
#include <string.h>

#define READ_FILE "./output.txt"
#define WRITE_FILE "./copy.txt"

static void using_fgets_and_fputs(FILE *read_file,FILE *write_file);
static void using_fgetc_and_fputc(FILE *read_file,FILE *write_file);

int main(void){
    FILE *file_read = fopen(READ_FILE,"r"),*file_write_s = fopen(WRITE_FILE,"w"),
        *file_write_c = fopen(WRITE_FILE,"w");
    
    if (!(file_read)){
        printf("Complete your challenge 1 before proceeding here\n");
        return 1;
    }else if(!(file_write_c || file_write_s)){
        printf("Error while creating the file %s\n",WRITE_FILE);
        return 1;
    }

    using_fgets_and_fputs();
    using_fgetc_and_fputc();
    fclose(file_read);
    return 0;
}


static void using_fgets_and_fputs(FILE *read_file,FILE *write_file){

}

static void using_fgetc_and_fputc(FILE *read_file,FILE *write_file){

}