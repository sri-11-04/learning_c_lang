/* 
⚡ Challenge 1: Memory & Sizeof Warmup

👉 Write a program that:

Declares variables of types: char, short, int, long, long long, float, double.

Prints their sizes using sizeof.

Declares:

a local variable (stack),

a global variable (data segment),

and a dynamically allocated array (heap).
Print their addresses to show the difference in memory regions.

💡 Example Output (will differ by system):
Size of char: 1
Size of int: 4
Size of double: 8

Address of local variable: 0x7ffdbe5f
Address of global variable: 0x60104c
Address of heap variable: 0x1f84020

*/


#include <stdio.h>
#include <stdlib.h>


int global;

int main(void){
    int local;
    int *heap= malloc(sizeof * heap);
    printf("Size of char: %zu\n",sizeof(char));
    printf("Size of int: %zu\n",sizeof(int));
    printf("Size of double: %zu\n",sizeof(double));
    printf("Size of long: %zu\n",sizeof(long));
    printf("Size of long long: %zu\n",sizeof(long long));
    printf("Size of float: %zu\n",sizeof(float));
    printf("Size of short: %zu\n",sizeof(short));

    printf("Address of the Local variable: %p\n",&local);
    printf("Address of the Global variable: %p\n",&global);
    printf("Address of the heap variable: %p\n",heap);
    free(heap);
    return 0;
}



/* 

*💡  What You’ll Notice

Local variable (&local) usually has a higher address (stack near top of memory).

Global (&global) is in a lower, fixed address region (data segment).

Heap (heap) grows upward from a middle region.

This helps visualize how memory is split between stack, heap, and globals.
*/