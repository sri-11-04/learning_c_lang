/* 
Write a program that:
Asks the user for two integers a and b.

Prints:
a + b
a - b
a * b
a / b (be careful with division by zero)
a % b
*/


#include <stdio.h>

int main(void){
    int a,b;
    printf("Enter two integers a b : ");
    scanf("%d %d",&a,&b);

    printf("%d + %d = %d\n",a,b,a+b);
    printf("%d - %d = %d\n",a,b,a-b);
    printf("%d x %d = %d\n",a,b,a*b);
    if (b == 0){
        printf("%d / %d is not possible as it may raise 0 division error\n",a,b);
        printf("%d %% %d is not possible as it may raise 0 division error\n",a,b); // as % is considered as place holder %% escape it
    }else{
        printf("%d / %d = %d\n",a,b,a/b);
        printf("%d %% %d = %d\n",a,b,a%b); // as % is considered as place holder %% escape it
    }
    return 0;
}