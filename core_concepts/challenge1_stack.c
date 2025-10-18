/* 
🔹 Challenge 1: Stack using Array

Description:
You need to implement a stack (LIFO = Last In, First Out) using an array in C.

Operations to support:

push(int x) → Add an element to the top of the stack.

pop() → Remove and return the top element (handle underflow).

peek() → Return the top element without removing it.

isEmpty() → Return true if stack is empty.

isFull() → Return true if stack is full.

Constraints:

Use a fixed-size array (say #define MAX 5 for testing).

Handle overflow (when pushing to a full stack) and underflow (when popping from an empty stack).

Print meaningful messages for operations.
*/


#include <stdio.h>
#include <stdlib.h>

#define MAX 5


typedef struct Stack Stack;

static void push(Stack *self,int value);

static int len(Stack *self);

static int pop(Stack *self);

static int peek(Stack *self);

static _Bool isEmpty(Stack *self);

static _Bool isFull(Stack *self);

static void print(Stack *self);

typedef struct Stack{
    int *arr;
    int capacity;
    int size;
    void (*push)(Stack *self,int value);
    int (*pop)(Stack *self);
    int (*peek)(Stack *self);
    int (*len)(Stack *self);
    _Bool (*isEmpty)(Stack *self);
    _Bool (*isFull)(Stack *self);
    void (*print)(Stack *self);
}Stack;


int main(void){
    Stack stack; // can i declare value directly like this {...};
    Stack *stack_p = &stack;
    stack.arr = malloc(MAX * sizeof *stack.arr);
    stack.capacity = MAX;
    stack.size = 0;
    stack.pop = pop;
    stack.push = push;
    stack.isEmpty = isEmpty;
    stack.isFull = isFull;
    stack.len = len;
    stack.peek = peek;
    stack.print = print;

    stack.push(stack_p,1);
    stack.push(stack_p,2);
    stack.push(stack_p,3);
    stack.push(stack_p,4);
    stack.push(stack_p,5);

    printf("Stacks top element is %d\n",stack.peek(stack_p));
    
    stack.pop(stack_p);
    stack.pop(stack_p);
    stack.pop(stack_p);
    stack.pop(stack_p);
    stack.pop(stack_p);
    stack.pop(stack_p);

    stack.print(stack_p);

    free(stack.arr);
    return 0;
}

static void push(Stack *self,int value){
    if (self->isFull(self)){
        printf("Stack is Full. Please remove a element before pushing\n");
        return;
    }
    *(self->arr+self->size) = value;
    printf("Added %d in the stack\n",value);
    self->size++;
}

static _Bool isEmpty(Stack *self){
    return self->len(self) == 0;
}

static int len(Stack *self){
    return self->size;
}

static _Bool isFull(Stack *self){
    return self->size == self->capacity;
}

static int pop(Stack *self){
    if (self->isEmpty(self)){
        printf("Pop is not allowed from empty Stack\n");
        return -1;
    }
    int res = *(self->arr+self->size-1);
    self->size--;
    printf("Popped %d from the Stack\n",res);
    return res;
}

static int peek(Stack *self){
    if (self->isEmpty(self)){
        printf("Cannot peek from an empty Stack\n");
        return -1;
    }
    return *(self->arr+self->size-1);
}

static void print(Stack *self){
    printf("[");
    for (int i = 0;i<self->size;i++){
        printf((i<self->size-1) ? "%d, " : "%d",*(self->arr+i));
    }
    printf("]\n");
}



