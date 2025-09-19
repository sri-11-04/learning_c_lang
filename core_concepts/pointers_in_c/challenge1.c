/* 
⚡ Challenge 1: Pointer Warmup

👉 Write a program that:

Declares an int x = 42;

Declares an int *p that points to x.

Declares an int **pp that points to p.

Prints:

Value of x

Address of x

Value stored in p

Value pointed by p

Value pointed by pp

Address of p

💡 Example Output (system-dependent):

x = 42
&x = 0x7ffc23d8
p = 0x7ffc23d8
*p = 42
pp = 0x7ffc23e0
*pp = 0x7ffc23d8
**pp = 42
*/


#include <stdio.h>

int main(void){
    int x = 42;
    int *p = &x;
    int **pp = &p; // pointer to a pointer & because with & only we get the address of the variable and * is deref (& | *var) as value

    printf("x = %d\n",x);
    printf("&x = %p\n",(void*)&x);
    printf("p = %p\n",(void*)p);
    printf("*p = %d\n",*p);
    printf("pp = %p\n",(void*)pp);
    printf("*pp = %p\n",(void*)*pp);
    printf("**pp = %d\n",**pp);
    return 0;
}


/* 
Your output will clearly show how:

p stores the address of x.

pp stores the address of p.

*pp brings you back to p.

**pp finally dereferences all the way to x.
*/