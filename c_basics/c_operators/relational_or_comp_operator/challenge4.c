/* 
Challenge 4: Leap Year Checker

A year is a leap year if:

divisible by 4,

but if divisible by 100 → must also be divisible by 400.

👉 Example: 2000 ✅, 1900 ❌, 2024 ✅.
*/


#include <stdio.h>

int main(void){
    int year;
    printf("Enter a year you want to check: ");
    scanf("%d",&year);
    if(!(year%400)){
        printf("%d is a leap year\n",year);
    }else if(!(year%4) && (year%100)){
        printf("%d is a leap year\n",year);
    }else{
        printf("%d is not a leap year\n",year);
    }
    return 0;
}