/* 
⚡ Challenge 2: Array Sizes & Layout

👉 Write a program that:

Declares arrays of different types:

int arr_int[5];

char arr_char[5];

double arr_double[5];

Prints:

The total size of each array (sizeof(arr)).

The size of one element (sizeof(arr[0])).

The number of elements (using sizeof(arr)/sizeof(arr[0])).

Prints the address of each element in each array, to observe how memory is laid out (contiguous).

💡 Example Output (system-dependent)

int array: total size = 20, element size = 4, count = 5
Element 0 address: 0x7ffd62b4
Element 1 address: 0x7ffd62b8
Element 2 address: 0x7ffd62bc
...

char array: total size = 5, element size = 1, count = 5
Element 0 address: 0x7ffd62af
Element 1 address: 0x7ffd62b0
...

double array: total size = 40, element size = 8, count = 5
Element 0 address: 0x7ffd62c0
Element 1 address: 0x7ffd62c8
...
*/


#include <stdio.h>

typedef enum{
    INT,
    CHAR,
    DOUBLE
}Types;

void print_arr(void *arr,Types type);

int main(void){
    int arr_int[] = {1,2,3,4,5};
    char arr_char[] = {'h','e','l','l','o','\0'};
    double arr_double[] = {1,2,3,4,5};

    print_arr(arr_int,INT);

    print_arr(arr_char,CHAR);

    print_arr(arr_double,DOUBLE);

    

    return 0;
}

void print_arr(void *arr,Types type){
    // need to work here
}