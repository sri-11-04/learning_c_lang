/* 
Challenge 1: Compare Two Numbers

Ask the user for two integers a and b.
Print whether:

a == b
a != b
a > b
a < b
a >= b
a <= b
*/

#include <stdio.h>

int main(void){
    int a , b;
    printf("Enter two integers (a b): ");
    scanf("%d %d",&a,&b);

    if (a == b){
        printf("%d == %d\n",a,b);
    }
    if (a != b){
        printf("%d != %d\n",a,b);
    }
    if (a > b){
        printf("%d > %d\n",a,b);
    }
    if (a < b){
        printf("%d < %d\n",a,b);
    }
    if (a >= b){
        printf("%d >= %d\n",a,b);
    }
    if (a <= b){
        printf("%d <= %d\n",a,b);
    }

    return 0;
}