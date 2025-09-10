/* 
🔹 Challenge 1: Maximum of an Array (C Warm-up)

👉 Task:
Write a C program that:

Asks the user for the number of elements (n).

Reads n integers into an array.

Finds and prints the maximum element in that array.

📝 Requirements

Use a function called largest() that takes the array and its size, and returns the maximum.

Use pointer notation (*(arr+i)) instead of just arr[i] to practice pointer access.

Make sure your program works for any valid n > 0.

💡 Example Run
Enter number of elements: 5
Enter element 0: 10
Enter element 1: 45
Enter element 2: 32
Enter element 3: 99
Enter element 4: 56
Maximum element is: 99
*/

#include <stdio.h>

int *fillIntArr(int *arr,int n){
    for (int i =0;i<n;i++){
        printf("Enter element %d: ",i);
        scanf("%d",arr+i);
    }
    return arr;
}

int largestInt(int *arr,int n){
    int max = *arr;
    for (int i = 0;i<n;i++){
        int cur = *(arr+i);
        if (cur>max) max = cur;
    }
    return max;
}

int main(void){
    int n,max;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    int nums[n];
    fillIntArr(nums,n);
    max = largestInt(nums,n);
    printf("Maximum element is: %d\n",max);
    return 0;
}