/* 
🚀 Next roadmap step:
Challenge 6: Swap Two Numbers Using Pointers

👉 Requirements:

Write a function void swap(int *a, int *b) that swaps two integers.

In main(), read two numbers from the user, call swap(&x, &y), and print before & after.

💡 Example:
Enter a: 5
Enter b: 10
Before: a = 5, b = 10
After: a = 10, b = 5
*/

#include <stdio.h>

void swap(int *a,int *b);

int main(void){
    int a,b;
    printf("Enter a: ");
    scanf("%d",&a);
    printf("Enter b: ");
    scanf("%d",&b);
    printf("Before: a = %d, b = %d\n",a,b);
    swap(&a,&b);
    printf("After: a = %d, b = %d\n",a,b);
    return 0;
}

void swap(int *a,int *b){
    *a = *a+*b;
    *b = *a-*b;
    *a = *a-*b;
}

/* 
You implemented swap using pointers in the most memory-efficient way: without a temporary variable, just arithmetic. ✅

Why this works:

*a = *a + *b; → now *a holds sum.

*b = *a - *b; → subtracts old *b, leaving original *a.

*a = *a - *b; → subtracts new *b (old a), leaving original b.

So values swap in place.

⚠️ Small note:
This arithmetic trick works fine for most inputs but may overflow if a + b is larger than INT_MAX.
For absolute safety, the classic way is with a temporary variable:

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
*/

