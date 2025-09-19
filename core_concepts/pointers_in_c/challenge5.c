/* 
⚡ Next roadmap step: Challenge 5: Pointers and Functions

👉 Write a program that:

Declares int x = 10;

A function void modify(int *p) that sets *p = 99;

In main(), pass &x to the function.

Print before and after calling the function.

📌 Expected Output:

Before: x = 10
After: x = 99

*/

#include <stdio.h>

void change_val(int *x,int val);

int main(void){
    int x = 10;
    printf("Before x: %d\n",x);
    change_val(&x,99);
    printf("After x: %d\n",x);
    return 0;
}

void change_val(int *x,int val){
    *x = val;
}