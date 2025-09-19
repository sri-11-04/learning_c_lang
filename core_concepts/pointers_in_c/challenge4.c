/* 
Challenge 4: Pointer vs Array Difference

👉 Write a program that:

Declares int arr[5] = {1,2,3,4,5};

Declares int *p = arr;

Prints:

sizeof(arr) vs sizeof(p)

&arr vs &p

arr+1 vs p+1

📌 Expected observations:

sizeof(arr) = total array size (20 bytes if int = 4 bytes).

sizeof(p) = size of pointer (8 bytes on 64-bit).

&arr = address of whole array (type: int (*)[5]), not same as p.
*/

#include <stdio.h>

int main(void){
    int arr[5] = {1,2,3,4,5};
    int *p = arr;

    printf("sizeof(arr) = %zu, sizeof(p) = %zu\n",sizeof(arr),sizeof(p));
    printf("&arr = %p, &p = %p\n",(void*)&arr,(void*)&p);
    printf("arr+1 = %p, p+1 = %p\n",(void*)(arr+1),(void*)(p+1));
    return 0;
}

/* 
✔️ Correct points in your program:

sizeof(arr) → gives total size of the array (5 × sizeof(int)).

sizeof(p) → size of the pointer (depends on system, usually 8 on 64-bit).

&arr vs &p → shows the subtle difference:

&arr is of type int (*)[5] → address of the whole array.

&p is of type int** → address of the pointer variable itself.

arr+1 → moves by 5 ints (because arr decays into int* only in most contexts, but as an array name here it means "next int element").

p+1 → also moves by 1 int (same as arr+1).

So your code demonstrates the exact differences clearly ✅

💡 If you print values of &arr and arr, you’ll notice they look the same numerically — but they are different types.

arr → type int* (decays to pointer to first element).

&arr → type int (*)[5] (pointer to entire array).

That’s one of the most confusing but fundamental distinctions in C.
*/