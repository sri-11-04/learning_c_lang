/* 
🔹 Challenge: Student with Address

Create a program that:
Defines two structs:
Address → contains street, city, pincode.
Student → contains name, roll, and an Address field.
Reads details for 1 student from the user.
Prints the student’s full details in a formatted way.
📌 Example Input / Output

Enter student name: Alice
Enter roll number: 101
Enter street: 21 MG Road
Enter city: Chennai
Enter pincode: 600001

--- Student Info ---
Name: Alice
Roll: 101
Address: 21 MG Road, Chennai - 600001

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Address
{
    char street[50];
    char city[50];
    unsigned int pincode;
}Address;


typedef struct Student
{
    char name[100];
    int roll;
    Address* address;
}Student;

void remove_escape(char str[]){
    int index = 0;
    while (*(str+index)!='\n'){index++;}
    *(str+index)='\0';
}

void clear_terminal(){
    while (getchar()!='\n');
}


void fill_student(Student *stu){
    printf("Enter student name: ");
    fgets(stu->name,100,stdin);    // replacement is scanf("%count[^\n]")
    remove_escape(stu->name);
    printf("Enter roll number: ");
    scanf("%d",&stu->roll);
    clear_terminal();
    printf("Enter street: ");
    fgets(stu->address->street,50,stdin);
    remove_escape(stu->address->street);
    printf("Enter city: ");
    fgets(stu->address->city,50,stdin);
    remove_escape(stu->address->city);
    printf("Enter pincode: ");
    scanf("%u",&stu->address->pincode);
}

void print_student(Student *stu){
    printf("--- Student Info ---\n");
    printf("Name: %s\n",stu->name);
    printf("Roll: %d\n",stu->roll);
    printf("Address: %s, %s - %u\n",stu->address->street,stu->address->city,stu->address->pincode);
}


int main(void){
    Student stu1;
    stu1.address = malloc(sizeof(Address)); // allocating a memory to the pointer
    fill_student(&stu1);
    print_student(&stu1);
    free(stu1.address); // freeing that memory
    return 0;
}