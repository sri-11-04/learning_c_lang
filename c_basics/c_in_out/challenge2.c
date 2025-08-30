/* 🔹 Challenge 2: Circle Area

👉 Ask the user for the radius of a circle (float) and print the area (use formula π * r * r, take π = 3.14159).
Example:
Input:
2.5
Output:
Area = 19.63
*/
#include <stdio.h>


int main(void){
    const float PI = 3.14159f; 
    float radius;
    double area;
    printf("Enter the radius of the circle: ");
    scanf("%f",&radius);
    area = PI* (radius*radius);
    printf("Input:\n%.1f\n",radius);
    printf("Output:\nArea = %.2f\n",area);
    return 0;
}