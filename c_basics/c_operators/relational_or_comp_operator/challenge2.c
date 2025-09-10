/* 
Challenge 2: Maximum of Three Numbers

Ask for three integers and print the largest using relational operators.

!easy sollution:
int max = a;
if (b > max) max = b;
if (c > max) max = c;

printf("Largest integer is %d\n", max);

*/

#include <stdio.h>

int main(void){
    int a,b,c;
    printf("Enter three integers (a b c): ");
    scanf("%d %d %d",&a,&b,&c);
    if (a==b && a==c){
        printf("three integers are equal\n");
    }else{
        if (a>=b && a>=c){
            printf("Largest integers is %d\n",a);
        }else if (b>=a && b>=c){
            printf("Largest integers is %d\n",b);
        }else{
            printf("Largest integers is %d\n",c);
        }
    }
    return 0;
}