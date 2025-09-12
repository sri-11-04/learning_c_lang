/* 
🔹 Challenge: Inverted Right-Angled Triangle of Characters

👉 Write a C program that prints an inverted right-angled triangle pattern like this (for n = 5 and character *):

*****
****
***
**
*

📝 Requirements

Ask the user for:

the number of rows (n),

the character to print.

Use nested loops to print the inverted triangle.

Validate that n >= 1.

💡 Example Input / Output

Enter number of rows: 5
Enter the char you want to print: *

*****
****
***
**
*

🔑 Function Signature Hint

void print_inverted_triangle(char c, int n);
*/

#include <stdio.h>

void print_triangle(char c, int n,_Bool is_inverted);

int main(void){
    int rows;
    char c;
    int inverted;

    printf("Enter number of rows: ");
    scanf("%d",&rows);
    getchar(); // can also handled by scanf(" %c",&c)
    printf("Enter the char you want to print: ");
    scanf("%c",&c);

    printf("Want to be inverted? (true -> 1 | false -> 0): ");
    scanf("%d",&inverted);

    print_triangle(c,rows,inverted);
    return 0;
}


void print_triangle(char c, int n,_Bool is_inverted){
    putchar('\n');
    for (int i = is_inverted ? n : 1 ;is_inverted ? i>0 : i<=n; is_inverted ? i-- : i++){
        for (int j = 1;j<=i;j++){
            printf("%c",c);
        }
        putchar('\n');
    }
}