/* 
Challenge 3: Swap Without Temporary Variable

Swap two integers a and b using only arithmetic operators (+ -).
👉 Example: a=5, b=3 → a=3, b=5
*/

#include <stdio.h>

void intSwap(int *a,int *b){
    *a = *a+*b;
    *b = *a-*b;
    *a = *a-*b;
}

int main(void){
    int a,b;
    printf("Enter two integers (a b) : ");
    scanf("%d %d",&a,&b);
    printf("a and b before swap => %d and %d\n",a,b);
    intSwap(&a,&b);
    printf("a and b after swap => %d and %d\n",a,b);
    return 0;
}