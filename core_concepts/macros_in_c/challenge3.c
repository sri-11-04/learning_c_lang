/* 
🔹 Challenge 3: Debug Mode with Preprocessor

Goal: Learn how #ifdef and #ifndef work.

Requirements:

Define a macro DEBUG at the top of your program.
#define DEBUG

Read two integers from the user.

Compute their sum.

If DEBUG is defined, print extra debug info (the numbers and their sum).
Otherwise, print only the sum.

Example Run 1 (DEBUG defined):
Enter first number: 5
Enter second number: 7
Debug: a=5, b=7, sum=12

Example Run 2 (DEBUG not defined):
Enter first number: 5
Enter second number: 7
Sum = 12

🔹 Hints:

Use #ifdef DEBUG to check if the macro is defined.

Use #else for the “not defined” branch.

End with #endif.
*/

#include <stdio.h>

#define DEBUG

static double sum(double a,double b){
    return a+b;
}

int main(void){
    double a,b,result;
    printf("Enter first number: ");
    scanf("%lf",&a);
    printf("Enter second number: ");
    scanf("%lf",&b);
    result = sum(a,b);
    #ifdef DEBUG
        printf("Debug: a = %.2lf, b = %.2lf, sum = %.2lf\n",a,b,result);
        // printf("hello\n");
    #else
        printf("sum = %.2lf\n",result);
    #endif
    return 0;
}


/* 
⚡ Notes & Tips

If you comment out #define DEBUG, the program automatically switches to the non-debug branch.

You could also define DEBUG at compile time instead of in the code:

gcc -DDEBUG program.c -o program

This way, you don’t have to modify the source file to turn debug mode on/off.

This shows the power of the preprocessor: the debug code is literally not compiled in the non-DEBUG case.
*/