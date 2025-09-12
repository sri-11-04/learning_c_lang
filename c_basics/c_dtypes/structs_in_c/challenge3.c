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


const int COUNT = 3;

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


void fill_Employee(Employee *emp)
{
    printf("ID: ");
    scanf("%u",&emp->emp_id);
    getchar();
    printf("Name: ");
    scanf("%99[^\n]",emp->name); // replacement is fgets(var,size_var,stdin); with removing the \n afterwards and before it we need to clear terminal using getchar()
    printf("Salary: ");
    scanf("%lf",&emp->salary);
    printf("Dept ID: ");
    scanf("%u",&emp->department->dept_id);
    getchar();
    printf("Dept Name: ");
    scanf("%99[^\n]",emp->department->dept_name); 
}

void fill_arr(Employee arr[],int n){
    for (int i = 0;i<n;i++){
        printf("Enter Employee %d details:\n",i+1);
        (arr+i)->department = malloc(sizeof(Department));
        fill_Employee(arr+i);
        putchar('\n');
    }
}

Employee* copy_employee(Employee arr[],int n){
    Employee *new_arr=malloc(n * sizeof(Employee));
    for (int i = 0;i<n;i++){
        *(new_arr+i) = *(arr+i);
        // copying Department pointer
        (new_arr+i)->department = malloc(sizeof(Department));
        *((new_arr+i)->department) = *((arr+i)->department);
    } 
    return new_arr;
}

void sort_emp(Employee arr[],int n){
    for (int i = 1;i<n;i++){
        Employee cur = *(arr+i);
        int j = i-1;

        while (j>=0 && (arr+j)->department->dept_id > cur.department->dept_id){
            *(arr+j+1) = *(arr+j);
            j--;
        }
        *(arr+j+1) = cur;
    }
}

void free_mem(Employee arr[],int n){
    for (int i = 0;i<n;i++){
        free((arr+i)->department);
    }
}

void print_employee(Employee arr[],int n){
    Employee* copy = copy_employee(arr,n);
    sort_emp(copy,n);
    for (int i = 0;i<n;i++){
        if (i==0 || (copy+i)->department->dept_id != (copy+i-1)->department->dept_id){printf("--- Department: %s ---\n",(copy+i)->department->dept_name);}
        printf("ID: %u, Name: %s, Salary: %.2lf\n",(copy+i)->emp_id,(copy+i)->name,(copy+i)->salary);
        if (i<n-1 && (copy+i)->department->dept_id != (copy+i+1)->department->dept_id)putchar('\n');
    }
    // freeing depatment memory
    free_mem(copy,n);
    free(copy);
}


/* 
* Notes: if we want to copy a nested struct with pointer we need to manually implement a deep copy 
  by allocating a new memory it and copying the content to it.
*/


int main(void)
{
    Employee arr[COUNT];
    fill_arr(arr,COUNT);
    print_employee(arr,COUNT);
    // freeing department memory
    free_mem(arr,COUNT);
    return 0;
}