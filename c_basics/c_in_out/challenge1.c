/* 🔹 Challenge 1: Sum of Two Numbers

👉 Ask the user for two integers and print their sum.
Example: 
Input:
5 7
Output:
Sum = 12
*/
#include <stdio.h>

int main(void){
    int a,b,sum;
    printf("Enter a value: ");
    scanf("%d",&a);
    // scanf("%d %d", &a, &b); // * can take multiple inputs with space sepration
    printf("Enter b value: ");
    scanf("%d",&b);
    printf("Input:\n%d %d\n",a,b);
    sum = a+b;
    printf("Output:\nSum = %d\n",sum);
    return 0;
}