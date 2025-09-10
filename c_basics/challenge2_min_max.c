/* 
🔹 Challenge 2: Minimum and Maximum of an Array

👉 Task
Write a C program that:

Asks the user for the number of elements (n).

Reads n integers into an array.

Finds both the minimum and maximum in one single scan.

Prints the results.

📝 Requirements

Use a function called find_min_max() that takes:

the array,

its size,

and two pointers to store results (min, max).

Use pointer notation (*(arr+i)) instead of array index.

Don’t loop twice — just one scan.
💡 Example Run
Enter number of elements: 5
Enter element 0: 10
Enter element 1: 45
Enter element 2: 32
Enter element 3: 99
Enter element 4: 56
Minimum element is: 10
Maximum element is: 99

🔑 Function Signature Hint
void find_min_max(int *arr, int n, int *min, int *max);

Inside, update *min and *max while scanning.

In main(), you’ll pass their addresses:

find_min_max(nums, n, &min, &max);
*/

#include <stdio.h>

void fill_int_arr(int *arr,int n){
    for (int i = 0;i<n;i++){
        printf("Enter element %d: ",i);
        scanf("%d",arr+i);
    }
}

void find_min_max(int *arr,int *min,int *max,int n){
    *max = *arr;
    *min = *arr;
    for (int i = 0;i<n;i++){
        int cur = *(arr+i);
        if (cur>*max) *max = cur;
        else if (cur < *min) *min = cur;
    }
}

int main(void){
    int n,min,max;
    int *pmin = &min,*pmax=&max;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    if (n<1){
        printf("Number elements should be atleast 1\n");
        return 1;
    }
    int nums[n];
    fill_int_arr(nums,n);
    find_min_max(nums,pmin,pmax,n);
    printf("Minimum element is: %d\n",min);
    printf("Maximum element is: %d\n",max);
    return 0;
}