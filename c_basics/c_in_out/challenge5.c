/* 
🔹 Challenge 5: Character Check

👉 Ask the user for a single character and tell whether it is:
    a digit
    a lowercase letter
    an uppercase letter
    or something else

Alternative with <ctype.h>
C already has built-in helpers:

    isdigit(c)
    isupper(c)
    islower(c)
    isalpha(c)
*/
#include <stdio.h>


int main(void){
    char c;
    printf("Give a char: ");
    c = getchar();

    if (c>='0' && c<='9'){
        printf("Given char %c is a digit\n",c);
    }else if (c>='A' && c<='Z'){
        printf("Given char %c is a uppercase letter\n",c);
    }else if (c>='a' && c<='z'){
        printf("Given char %c is a lowercase letter\n",c);
    }else{
        printf("Given char %c is something else\n",c);
    }

    // printf("%d-%d\n",'A','Z');
    return 0;
}