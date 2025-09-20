/* 
⚡ Challenge 4 (next step):
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
    int *temp = realloc(*p,size * sizeof **p);
    if (temp != NULL){
        *p = temp;
    }
}

void read_int_arr(int *arr,int n,int start){
    for (int i = 0+start;i<n;i++){
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


/* 
Check realloc carefully
If realloc fails, it returns NULL but the original pointer remains valid.
In your current code:
resize(&arr, n+extra);
if (arr == NULL) {
    printf("Error while creating memory.\n");
    return 1;
}
👉 Here, if realloc fails, arr is still the old pointer (not NULL).
To be 100% safe, resize should use a temporary pointer:
void resize(int **p, int size) {
    int *tmp = realloc(*p, size * sizeof **p);
    if (tmp != NULL) {
        *p = tmp;
    }
}
This way, you don’t lose the original block if realloc fails.
*/