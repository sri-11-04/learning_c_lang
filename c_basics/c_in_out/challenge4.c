/* 🔹 Challenge 4: Reverse a String

👉 Ask the user for a word (string without spaces) and print it in reverse.
Example:

Input:
hello
Output:
olleh
*/

#include <stdio.h>
#include <string.h>

char *strReverse(char *string){  // * strrev is a string.h func which can also reverse string
    short l=0,r=strlen(string)-1;
    while(l<r){
        char temp = *(string + l);
        *(string + l++) = *(string + r);
        *(string + r--) = temp;
    }

    return string;
}

int main(void){
    char string[250];

    printf("Enter a word to reverse: ");
    scanf("%s",string);
    printf("Given word before reverce: %s\n",string);
    strReverse(string);
    printf("Given word after reverce: %s\n",string);
    return 0;
}