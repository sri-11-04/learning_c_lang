/* 🔹 Challenge 3: Full Name Input

👉 Ask the user for their full name and print:

First line: "Hello, <name>"

Second line: "Length of your name is X"

(Use fgets so spaces are allowed)
*/

#include <stdio.h>
#include <string.h>

int main(void){
    char name[2000];
    int len; // as char stores -128 to 127

    // printf("%lu\n",sizeof(name)); // returns UL buffer size of the array
    printf("Enter your full name: ");
    fgets(name,sizeof(name),stdin);

    len = strlen(name);

    if (*(name+(len-1)) == '\n'){
        *(name+(len-1)) = '\0'; // this char is crusial in C. this acts as the stop value even the fgets by default it to '\0' at last but here we also need to remove \n so we do this
        len--;
    }

    printf("Hello, %s\n",name);

    printf("Length of your name is %d\n",len);

    // printf("%p\n",stdin);

    // printf("%c , %d\n",'A','A'); // ? %c prints char %d of char prints its AScii value
    return 0;
}