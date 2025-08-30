/* 
Challenge 4: Simple Interest Calculator

Formula:

        SI= (P×R×T)/100
	
where
P = Principal
R = Rate of interest
T = Time

Write a program to compute SI.
*/

#include <stdio.h>

double simple_interest_calc(int p,float r,int t){
    return ((double)p*r*t)/100;
}

int main(void){
    int p,t;
    float r;
    double si;
    printf("Enter the principle amount: ");
    scanf("%d",&p);
    printf("Enter the interest rate: ");
    scanf("%f",&r);
    printf("Enter the period: ");
    scanf("%d",&t);
    si = simple_interest_calc(p,r,t);
    printf("The simple interest is %.2f\n",si);
    return 0;
}