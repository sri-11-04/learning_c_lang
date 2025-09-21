#include <stdio.h>

static void increment(TaskManager *self);
static void add_task(TaskManager *self,Task *task);
static void view_task(TaskManager *self);


typedef enum{
    COMPLETED,
    INCOMPLETED
}Status;

typedef struct{
    int id;
    char name[100];
    Status status;
}Task;

typedef Task Data[100];

typedef struct{
    Data task_arr;
    int serial;
    void (*increment)(TaskManager *self);
}TaskManager;



int main(void){
    TaskManager task_manager;

    return 0;
}

static void increment(TaskManager *self) {self->serial+=1;}
