/* 
🔹 Challenge: Simple Calculator in C

👉 Write a program that:

Asks the user to enter two numbers.

Asks for an operator (+, -, *, /).

Performs the operation using a separate function for each (add, subtract, multiply, divide).

Prints the result.

📝 Requirements

Use functions:

int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
float divide(int a, int b); // must handle divide by zero

Use a switch-case in main() to decide which function to call.

Validate division by zero properly.

Bonus: Allow the calculator to repeat until user quits.

💡 Example Run

Enter first number: 10
Enter second number: 5
Enter operator (+, -, *, /): /

Result: 2.00

*/

#include <stdio.h>

int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
float divide(int a, int b);

int main(void){
    int a,b;
    char op;

    printf("Enter first number: ");
    scanf("%d",&a);

    printf("Enter second number: ");
    scanf("%d",&b);

    printf("Enter operator (+, -, *, /): ");
    scanf(" %c",&op);

    // switch()

    return 0;
}