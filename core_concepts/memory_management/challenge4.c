/* 
👉 Write a program that:

Asks the user for n.

Dynamically allocates memory for n integers.

Reads values into the array.

Prints them back.

Frees the memory.


⚡ Challenge 8 (next step):
👉 Modify this program so that after the array is created and filled:

Ask the user for extra elements to add.

Use realloc to expand the memory.

Read the new values and print the whole array again.
*/


#include <stdio.h>
#include <stdlib.h>

void create_memory(int **p,int size);
void resize(int **p,int size);
void read_int_arr(int *arr,int n,int start);
void print_int_arr(int *arr,int n);

int main(void){
    int n,extra;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    int *arr;
    create_memory(&arr,n);
    if (arr == NULL){
        printf("Error while creating memory.\n");
        return 1;
    }
    read_int_arr(arr,n,0);
    print_int_arr(arr,n);
    printf("Enter the extra size: ");
    scanf("%d",&extra);
    if (extra>0){
        resize(&arr,n+extra);
        if (arr == NULL){
            printf("Error while creating memory.\n");
            return 1;
        }
        read_int_arr(arr,n+extra,n);
        print_int_arr(arr,n+extra);
    }
    free(arr);
    return 0;
}

void create_memory(int **p,int size){
    *p = calloc(size,sizeof **p);
}

void resize(int **p,int size){
    *p = realloc(*p,size * sizeof **p);
}

void read_int_arr(int *arr,int n,int start){
    for (int i = 0+start+(start) ? 1 : 0;i<n;i++){
        printf("Enter %dth element: ",i);
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