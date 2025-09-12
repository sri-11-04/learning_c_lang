/* 

* in these file we will learn about void pointer and typedef

! void
void pointer is also known as unknown pointer same as type of Object in java
it can allow any type pointers but we need to type convert it before use it
but in c the type conversion is auto..

mallac returns a void pointer

! typedef
it is nothing but an alias
*/


#include <stdio.h>

// * typedef

// ? struct alias as Struct
typedef struct{
    int id;
    char name[50];
} Struct;

// ? array alias as int_array of 10 length
typedef int int_array[10];




int main(void){
    // * defining variable of diferent types
    int num = 10;
    double d_num = 10;
    char c = 'a';
    char name[] = {'h','e','l','l','o','\0'};

    void *universal_p; // * creating an univerasal pointer

    // ? testing
    universal_p = &num; // * assigning int
    printf("converted to int %d\n",*(int*)universal_p); // * this is the way to derefernce it (int*) is type casting

    universal_p = &d_num; // * assigning double
    printf("converted to double %lf\n",*(double*)universal_p); // * this is the way to derefernce it (double*) is type casting

    universal_p = &c; // * assigning char
    printf("converted to char %c\n",*(char*)universal_p); // * this is the way to derefernce it (char*) is type casting

    universal_p = name; // * assigning char array
    printf("converted to char array %s\n",(char*)universal_p); // * this is the way to derefernce it (char*) is type casting no need to deref it 


    //  calling from typedef
    Struct st = {1,"sri annamalai"};
    int_array arr;
    return 0;
}