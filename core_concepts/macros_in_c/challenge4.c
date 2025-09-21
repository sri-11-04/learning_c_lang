/* 
🔹 Challenge 4: Logging Macro

Goal: Combine object-like macros, function-like macros, and conditional compilation to create a simple logging system.

Requirements:

Define a macro DEBUG at the top (or allow defining it at compile-time).

Define a macro function LOG(msg) that:

Prints "LOG: <msg>" only if DEBUG is defined.

Does nothing if DEBUG is not defined.

In main():

Read an integer from the user.

Use LOG to print "User entered: <number>".

Print "Number squared: <number*number>" (always printed, regardless of DEBUG).

Example Run 1 (DEBUG defined):
Enter a number: 5
LOG: User entered: 5
Number squared: 25

Example Run 2 (DEBUG not defined):
Enter a number: 5
Number squared: 25

🔹 Hints:

Use #ifdef DEBUG inside the macro definition.

Use a do-while trick to make the macro safe with semicolons:
#define LOG(msg) do {  your code  } while(0)

Try printing different types: strings, integers, floats.

*/


#include <stdio.h>

#define SQUARE(num) ((num)*(num))

#ifdef DEBUG
    #define LOG(msg) printf("Log: User entered: %.2lf\n",msg)
    //  #define LOG(fmt, ...) do { \  // fmt is a string litral and ... is varargs 
    //     printf("LOG: " fmt "\n", __VA_ARGS__); \ // i think in c we can do "helo" "hi" "guys" => "hello"+"hi"+"guys"
    // } while(0)
#else
    #define LOG(msg)
#endif

int main(void){
    double num;
    printf("Enter a number: ");
    scanf("%lf",&num);
    LOG(num);
    printf("Number squared: %.2lf\n",SQUARE(num));
    return 0;
}