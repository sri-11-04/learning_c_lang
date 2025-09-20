/* 
🔹 Challenge 1 (Starter)

Write a program that:

Defines an object-like macro PI as 3.14159.

Defines a function-like macro CIRCLE_AREA(r) to compute area.

Reads a radius from the user.

Prints the area using the macro.

📌 Example:
Enter radius: 5
Area = 78.53975
*/

#include <stdio.h>

#define PI 3.14159
#define CIRCLE_AREA(r) (PI*(r)*(r))

int main(void){
    double area,radius;
    printf("Enter radius: ");
    scanf("%lf",&radius);
    area = CIRCLE_AREA(radius);
    printf("Area: %.5lf\n",area);
    return 0;
}