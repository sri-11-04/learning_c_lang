/* 
🧩 Challenge 4 — Text File Reader/Writer

Goal:
Build a simple program that writes user input to a text file and then reads and displays it.

📋 Description:

You’ll create a program that:

Asks the user to enter a few lines of text (say 3–5 lines).

Writes them to a text file (output.txt).

Then reopens the same file and displays the contents on the screen.

🧠 Requirements:

Use file handling functions:
fopen(), fprintf(), fgets(), fclose().

Handle file open errors properly.

Ensure all file streams are closed before program exit.

⚙️ Example I/O

Enter number of lines: 3
Enter line 1: Hello C
Enter line 2: File Handling is fun!
Enter line 3: Let's read this later.

✅ Data written to output.txt successfully!

📖 Reading file content:
--------------------------------
Hello C
File Handling is fun!
Let's read this later.
--------------------------------

*/

#include <stdio.h>
#include <string.h>

#define FILE_NAME "./output.txt"
#define MAX 100

static void writeFile(FILE *file,char string[],int lines);

static void readFile(FILE *file,char string[]);

int main(){
    FILE *file = fopen(FILE_NAME,"w+");
    if (file == NULL){
        printf("ERROR : Creating file %s\n",FILE_NAME);
        return 1;
    }
    int lines;
    char string[MAX];
    printf("Enter number of lines: ");
    scanf("%d",&lines);
    writeFile(file,string,lines);
    readFile(file,string);
    fclose(file);
    return 0;
}

void writeFile(FILE *file,char string[],int lines){
    while(getchar() != '\n');
    for (int i = 1;i<=lines;i++){
        printf("Enter line %d: ",i);
        fgets(string,MAX,stdin);
        string[strcspn(string,"\n")] = '\0';
        fprintf(file,"%s\n",string);
    }
    printf("\nData written to %s successfully!\n\n",FILE_NAME);
}

void readFile(FILE *file,char string[]){
    rewind(file);
    printf("Reading file content:\n--------------------------------\n");
    while (fgets(string,MAX,file) != NULL){
        printf(string); // but prefer to use "%s",string because if the string contain any % it will be consider as format
    }
    printf("--------------------------------\n");
}

