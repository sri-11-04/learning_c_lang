/* 
⚡ Challenge 3: Pointer Arithmetic Exploration
Write a program that:

Declares int arr[5] = {100,200,300,400,500};

Prints:

p and p+1 (addresses should differ by sizeof(int)).

*p and *(p+1) (values at those addresses).

Loop through array using only pointers (no arr[i]).

Example snippet of output:

p = 0x7ffc23c0, p+1 = 0x7ffc23c4
*p = 100, *(p+1) = 200
...

*/

#include <stdio.h>

void print_int_arr(int *p,int n);

int main(void){
    int arr[5] = {100,200,300,400,500};
    int *p = arr;

    printf("p = %p, p+1 = %p\n",(void*)p,(void*)(p+1));
    printf("*p = %d, *(p+1) = %d\n\n",*p,*(p+1));
    print_int_arr(p,5);
    return 0;
}

void print_int_arr(int *p,int n){
    for (int i = 0;i<n;i++){
        printf("*(p+%d) = %d\n",i,*(p+i));
    }
}

/* 
💡 Extra things to note:

Pointer arithmetic is scaled automatically:

If p is int*, then p+1 means "go forward sizeof(int) bytes".

If it were double*, p+1 would move sizeof(double) (8 bytes on most systems).

That’s why pointer arithmetic is type-aware — it’s not raw byte arithmetic.
*/