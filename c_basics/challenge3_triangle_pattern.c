/* 
🔹 Challenge: Right-Angled Triangle of Stars

Write a C program that prints a right-angled triangle pattern of * like this (for n = 5):

*
**
***
****
*****

👉 Requirements:

Ask the user to enter a number n.

Use nested loops (for loops).

Print stars * row by row.

📌 Example Input / Output:

Enter number of rows: 5

*
**
***
****
*****
*/


#include <stdio.h>

void print_triangle_pattern(char c,int n){
    for (int i = 1;i<=n;i++){
        for (int j = 0;j<i;j++){
            printf("%c",c);
        }
        putchar('\n');
    }
}

int main(void){
    int n;
    char c;
    printf("Enter number of rows: ");
    scanf("%d",&n);
    if (n<1){
        printf("Number of rows should atleast be 1\n");
        return 1;
    }
    printf("Enter the char you want to print: ");
    scanf(" %c",&c);
    putchar('\n');
    print_triangle_pattern(c,n);
    return 0;
}