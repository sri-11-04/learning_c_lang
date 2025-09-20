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

// ! need to script
#include <stdio.h>

#define DEBUG
#ifdef DEBUG
    #define LOG(msg) printf("Log")
#else

#endif