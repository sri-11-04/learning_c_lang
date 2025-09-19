/* 
challenge 8: Dynamic Memory Allocation with malloc()

👉 Write a program that:

Asks the user for n.

Dynamically allocates memory for n integers.

Reads values into the array.

Prints them back.

Frees the memory.
*/

#include <stdio.h>
#include <stdlib.h>

void read_int_arr(int *arr,int n);
void print_int_arr(int *arr,int n);

int main(void){
    int n;
    printf("Enter the count of the array: ");
    scanf("%d",&n);
    int *d_arr = malloc(n * (sizeof *d_arr));
    if (d_arr == NULL) {
        printf("Error while creating a memory.\n");
        return 1;
    }
    read_int_arr(d_arr,n);
    print_int_arr(d_arr,n);
    free(d_arr);
    return 0;
}

void read_int_arr(int *arr,int n){
    for (int i = 0;i<n;i++){
        printf("Enter %d index's value: ",i);
        scanf("%d",arr+i);
    }
}

void print_int_arr(int *arr,int n){
    printf("[");
    for (int i = 0;i<n;i++){
        printf((i<n-1) ? "%d, " : "%d",*(arr+i));
    }
    printf("]\n");
}



/* 
✔️ Used malloc with sizeof *d_arr (avoids hardcoding type).
✔️ Checked malloc result for NULL.
✔️ Used helper functions for clarity (read_int_arr, print_int_arr).
✔️ Freed memory with free(d_arr).
✔️ Correct pointer arithmetic in scanf("%d", arr + i) and *(arr+i).

This is exactly how dynamic allocation should be done in modern C.
*/

