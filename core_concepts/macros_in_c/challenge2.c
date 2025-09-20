/* 
🚀 Ready for Challenge 2?
👉 Create a program with a macro MAX(a,b) that returns the larger of two numbers.

Read two integers from the user.

Use the macro to find the maximum.

Print the result.
*/

#include <stdio.h>

#define MAX(a,b) ((a)>(b)?(a):(b))

int main(void){
    int a,b;
    printf("Enter first integer: ");
    scanf("%d",&a);
    printf("Enter second integer: ");
    scanf("%d",&b);
    printf("Max integer among %d and %d is %d\n",a,b,MAX(a,b));
    return 0;
}