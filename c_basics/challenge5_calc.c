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
#include <stdlib.h>

int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
float divide(int a, int b);

typedef union{
    int i;
    float f;
    char *str;
} Value;

typedef enum{
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_STRING
}TypeEnum;

typedef struct{
 TypeEnum type;
 int a;
 int b;
 char op;
 Value res;
} Calc;


int main(void){
    Calc calc;
    _Bool can_break=0;
    char exit;
    printf("Welcome to Calulator App!!!\n");
    while (1){
        putchar('\n');
        printf("Enter first number: ");
        scanf("%d",&calc.a);

        printf("Enter second number: ");
        scanf("%d",&calc.b);

        while(!can_break){
            printf("Enter operator (+, -, *, /, x): ");
            scanf(" %c",&calc.op);
            switch(calc.op){
                case '+':
                    calc.type = TYPE_INT;
                    calc.res.i = add(calc.a,calc.b);
                    can_break = 1;
                    break;
                case '-':
                    calc.type = TYPE_INT;
                    calc.res.i = subtract(calc.a,calc.b);
                    can_break = 1;
                    break;
                case '*':
                    calc.type = TYPE_INT;
                    calc.res.i = multiply(calc.a,calc.b);
                    can_break = 1;
                    break;
                case 'x':
                    calc.type = TYPE_INT;
                    calc.res.i = multiply(calc.a,calc.b);
                    can_break = 1;
                    break;
                case '/':
                    if (calc.b!=0){
                        calc.type = TYPE_FLOAT;
                        calc.res.f = divide(calc.a,calc.b);
                    }
                    else{
                        calc.type = TYPE_STRING;
                        // calc.res.str = malloc(50*sizeof(char)); // * no need to use malloc as the pointer str already has a memory
                        calc.res.str = "Division by Zero is impossible";
                    }
                    can_break = 1;
                    break;
                default:
                    printf("Invalid operator!!!\n");
                    can_break = 0;
            }
        }
        putchar('\n');
        switch(calc.type){
            case TYPE_INT:
                printf("Result: %d\n",calc.res.i);
                break;
            case TYPE_FLOAT:
                printf("Result: %.2f\n",calc.res.f);
                break;
            case TYPE_STRING:
                printf("Error: %s\n",calc.res.str);
                // free(calc.res.str);
                break;
        }
        getchar();
        printf("Continue to do math? (y|n): ");
        scanf("%c",&exit);
        if (exit != 'y'){
            printf("Thank you!\n");
            break;
        }else can_break = 0;
    }
    

    return 0;
}

int add(int a,int b){
    return a+b;
}

int subtract(int a,int b){
    return a-b;
}

int multiply(int a,int b){
    return a*b;
}

float divide(int a,int b){
    return (float) a/b;
}