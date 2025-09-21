/* 
🔹 Challenge 5: Auto Log with File, Line, and Time

Goal: Upgrade your logging system using predefined macros.

Requirements:

Use predefined macros:

__FILE__ → current filename.

__LINE__ → current line number.

__TIME__ → current compilation time.

__DATE__ → current compilation date.

Define a macro LOG(msg, ...) that prints in this format:
[filename:line | date time] LOG: <your message>

If DEBUG is not defined, LOG should do nothing.

In main():

Read a number.

Use LOG to print something like:
[main.c:18 | Sep 21 15:42:10] LOG: User entered 10
Always print the square of the number, just like before.

Example Run (with DEBUG defined):
Enter a number: 7
[main.c:19 | Sep 21 15:42:10] LOG: User entered 7
Number squared: 49

Example Run (with DEBUG not defined):
Enter a number: 7
Number squared: 49

🔹 Hints:

Use printf("[%s:%d | %s %s] LOG: ...\n", __FILE__, __LINE__, __DATE__, __TIME__, ...).

Wrap it in do { } while(0) for safety.
*/

#include <stdio.h>

#define SQUARE(num) ((num)*(num))

#ifdef DEBUG
    #define LOG(frmt,...) do { printf("[%s:%d | %s %s] Log: " frmt "\n",__FILE__,__LINE__,__DATE__,__TIME__, ##__VA_ARGS__);} while (0)
#else
    #define LOG(frmt,...)
#endif


int main(void){
    double num;
    printf("Enter a number: ");
    scanf("%lf",&num);
    LOG("User entered %.2lf",num);
    printf("Number squared: %.2lf\n",SQUARE(num));
    return 0;
}