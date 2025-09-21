#include <stdio.h>


typedef enum{
    INCOMPLETE,
    COMPLETED
}Status;

typedef struct{
    int id;
    char name[100];
    Status status;
}Task;

typedef Task Data[100];

struct TaskManager{
    int size;
    int capacity;
    int serial;
    Data task_arr;
    int (*increment)(struct TaskManager *self);
    _Bool (*add_task)(struct TaskManager *self, Task *task);
    void (*view_task)(struct TaskManager *self);
};

static int increment(struct TaskManager *self);
static _Bool add_task(struct TaskManager *self,Task *task);
static void view_task(struct TaskManager *self);

int main(void){
    Data arr;
    struct TaskManager task_manager ;
    task_manager.size=0;
    task_manager.capacity=100;
    task_manager.serial=1;
    *task_manager.task_arr = *arr;
    task_manager.increment = increment;
    task_manager.add_task = add_task;
    task_manager.view_task = view_task;
    // {0,100,1,arr,increment,add_task,view_task};
    int choice;
    Task task;
    _Bool run = 1;
    while(run){
        printf("1. Add Task\n2. View Tasks\n3. Exit\nchoose: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter task name: ");
                scanf(" %99[^\n]",task.name);
                printf("[%d] %s %s\n",__LINE__,__TIME__,task.name);
                task.status = INCOMPLETE;
                if (task_manager.add_task(&task_manager,&task)){
                    printf("Task added!\n");
                }else{
                    printf("No space in memory to add task!\n");
                    run = 0;
                }
                break;
            case 2:
                task_manager.view_task(&task_manager);
                break;
            case 3:
                printf("Goodbye!!. Have a nice day\n");
                run=0;
                break;
            default:
                printf("Invalid input\n");
        }
        putchar('\n');
    }
    return 0;
}

static int increment(struct TaskManager *self) {return self->serial++;}
static _Bool add_task(struct TaskManager *self,Task *task){
    if (self->size == self->capacity) return 0;
    task->id = self->increment(self);
    *(self->task_arr+self->size) = *task;
    self->size++;
    return 1;
}
static void view_task(struct TaskManager *self){
    for (int i = 0;i<self->size;i++){
        printf("[%d] %s - %s\n",(self->task_arr+i)->id,(self->task_arr+i)->name,((self->task_arr+i)->status) ? "Completed" : "Pending");
    }
}
