#include <stdio.h>

/* 
👉 Challenge for you:
Write a program that:

Stores details of 5 students (roll, name, marks).

Prints only the student with the highest marks.
*/

struct Student {
    int roll;
    char name[250];
    double marks;

    void (*print)(struct Student stu);
};

void print(struct Student stu){
    printf("Roll: %d, Name: %s, Marks: %.2lf\n",stu.roll,stu.name,stu.marks);
}

void fill_students(struct Student arr[],int n){
    for (int i = 0;i<n;i++){
        printf("Enter the Student %d's (roll name marks): ",i+1);
        scanf("%d %s %lf",&((arr+i)->roll),(arr+i)->name,&((arr+i)->marks));
        // printf("-----\n");
        (arr+i)->print = print;
        // printf("-----\n");
    }
}

int highest_marks_index(struct Student arr[],int n){
    int index = 0;
    for (int i = 1;i<n;i++){
        if ((arr+i)->marks > (arr+index)->marks) index = i;
    }
    return index;
}


void print_students(struct Student arr[],int n){
    printf("--- Student Records ---\n");
    for (int i = 0; i<n;i++){
        (arr+i)->print(*(arr+i));
    }
}



int main(void){
    int count;
    printf("Enter the number of students: ");
    scanf("%d",&count);

    struct Student students_db[count];

    fill_students(students_db,count);

    print_students(students_db,count);

    printf("Student with the highest mark.....\n");

    students_db->print(*(students_db+highest_marks_index(students_db,count)));

    return 0;
}