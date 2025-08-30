/* 
Challenge 2: Average of 3 Numbers

Ask the user for 3 integers. Calculate and print their average using arithmetic operators.
*/

#include <stdio.h>

int main(void){
    int a,b,c;
    double avg;

    printf("Enter integer of a b c : ");
    scanf("%d %d %d",&a,&b,&c);
    avg = (a+b+c)/3.0; // * another way avg = ((double)a + b + c) / 3; this will handle the int overflow too
    printf("The average for %d, %d, %d is %.4f\n",a,b,c,avg);
    return 0;
}