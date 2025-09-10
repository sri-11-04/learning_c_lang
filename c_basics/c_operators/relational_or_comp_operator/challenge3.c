/* 
Challenge 3: Voting Eligibility

Ask the user for their age.

If age >= 18 → "Eligible to vote"

Else → "Not eligible to vote"
*/

#include <stdio.h>

int main(void){
    char age;
    printf("Enter your age: ");
    scanf("%d",&age);
    if (age<1) {
        printf("age cannot be less than 1\n");
        return 1;
    }
    printf("%s to vote\n",(age >= 18) ? "Eligible" : "Not eligible"); 
    return 0;
}


/* 
! gpt result

#include <stdio.h>

int main(void) {
    int age;
    printf("Enter your age: ");
    scanf("%d", &age);

    if (age < 1 || age > 120) {
        printf("Invalid age entered\n");
        return 1;
    }

    printf("%s to vote\n", (age >= 18) ? "Eligible" : "Not eligible");
    return 0;
}

*/