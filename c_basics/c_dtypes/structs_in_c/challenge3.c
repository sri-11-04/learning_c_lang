/* 
🔹 Challenge: Employee Records with Department

👉 Create a program that:

Defines two structs:

Department → dept_id, dept_name

Employee → emp_id, name, salary, and a Department (embedded struct, not pointer).

Reads details of 3 employees from the user.

Prints all employees, grouped by department (employees in the same department should appear together).

📌 Example Input

Enter Employee 1 details:
ID: 101
Name: Alice
Salary: 50000
Dept ID: 1
Dept Name: HR

Enter Employee 2 details:
ID: 102
Name: Bob
Salary: 60000
Dept ID: 2
Dept Name: IT

Enter Employee 3 details:
ID: 103
Name: Charlie
Salary: 55000
Dept ID: 1
Dept Name: HR

📌 Example Output
--- Department: HR ---
ID: 101, Name: Alice, Salary: 50000.00
ID: 103, Name: Charlie, Salary: 55000.00

--- Department: IT ---
ID: 102, Name: Bob, Salary: 60000.00

⚡ Hints:
    Use struct inside struct (no pointers for now).
    After input, you’ll need to group by dept_id before printing.
    You can do this by scanning employees and printing those that match the department.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    unsigned int dept_id;
    char dept_name[100];
}Department;

typedef struct
{
    unsigned int emp_id;
    char name[100];
    double salary;
    Department *department;
}Employee;

typedef Department dept_array[3];

void fill_Employee(Employee *emp)
{
    printf("ID: ");
    scanf("%u",&emp->emp_id);
    printf("Name: ");
    scanf("%99[^\n]"); // replacement is fgets(var,size_var,stdin); with removing the \n afterwards and before it we need to clear terminal using getchar()
    printf("Salary: ");
    scanf("%lf",&emp->salary);
    printf(""); // ! continue here
}

int main(void)
{
    dept_array arr;


    return 0;
}