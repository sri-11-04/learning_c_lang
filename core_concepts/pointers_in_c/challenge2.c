/* 
⚡ Challenge 2: Array & Pointer Relationship
Write a program that:

Declares int arr[5] = {10,20,30,40,50};

Declares an int *p = arr; (notice no &)

Prints:

Address of arr[0] and p (should match).

Each element using array indexing (arr[i]).

Each element using pointer arithmetic (*(p+i)).

💡 Example Output:

arr[0] address: 0x7ffc23c0
p = 0x7ffc23c0
arr[0] = 10, *(p+0) = 10
arr[1] = 20, *(p+1) = 20
...

*/


#include <stdio.h>

void print_int_arr(int arr[],int *p,int n);

int main(void){
    int arr[5] = {10,20,30,40,50};
    int *p = arr;

    printf("arr[0] address: %p\n",(void*)&arr[0]);
    printf("p = %p\n\n",(void*)p);
    print_int_arr(arr,p,5);
}

void print_int_arr(int arr[],int *p,int n){
    for (int i = 0;i<n;i++){
        printf("arr[%d] = %d, *(p+%d) = %d\n",i,arr[i],i,*(p+i));
    }
}


/* 
You’ve shown exactly how arrays and pointers are related:

int *p = arr; works because the array name decays to a pointer to its first element.

&arr[0] and p print the same address → confirms that p points to the start of the array.

Your helper function print_int_arr is neat — makes the code cleaner.

Using (void*) in address printing = correct & portable.

💡 Extra insights to strengthen your understanding:

arr (as a variable in expressions) → pointer to first element.

But sizeof(arr) ≠ sizeof(p) →

sizeof(arr) = total array size (5 * 4 = 20 bytes for int arr[5]).

sizeof(p) = size of pointer (usually 8 bytes on 64-bit).

So while arr behaves like a pointer, it’s not exactly a pointer (it’s an array type that can decay into one).
*/


