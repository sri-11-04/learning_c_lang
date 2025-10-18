/* 
🔹 Challenge 2: Queue using Array

Description:
You need to implement a queue (FIFO = First In, First Out) using an array in C.

Operations to support:

enqueue(int x) → Add an element to the rear.

dequeue() → Remove and return the front element.

peek() → Return the front element without removing it.

isEmpty() → Return true if queue is empty.

isFull() → Return true if queue is full.

Constraints:

Use a fixed-size array (#define MAX 5).

Handle overflow (when enqueuing to a full queue) and underflow (when dequeuing from empty queue).

Print meaningful messages for each operation.

⚡ Extra Twist: Circular Queue

In a normal (linear) queue with an array, after a few enqueues and dequeues, space at the front goes unused.
👉 So, use a circular queue approach where rear and front wrap around using modulo (%).

Key idea:

front → index of the first element.

rear → index of the last element.

Initially: front = -1, rear = -1.

On enqueue:

If empty → front = rear = 0.

Else → rear = (rear + 1) % capacity.

On dequeue:

If only one element → reset to empty (front = rear = -1).

Else → front = (front + 1) % capacity.

print logic idx = (self->first + i) % self->capacity;
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct Queue Queue;

static void print(Queue *self);

static void enqueue(Queue *self,int value);

static int *dequeue(Queue *self);

static int *peek(Queue *self);

static _Bool isEmpty(Queue *self);

static _Bool isFull(Queue *self);

struct Queue
{
   int *arr;
   int capacity;
   int size;
   int first;
   int rear;
   void (*enqueue)(Queue *self,int value);
   void (*print)(Queue *self);
   int *(*dequeue)(Queue *self);
   int *(*peek)(Queue *self);
   _Bool (*isEmpty)(Queue *self);
   _Bool (*isFull)(Queue *self); 
};


int main(void){
    Queue queue = {.capacity=MAX,
        .size=0,
        .first=-1,
        .rear=-1,
        .enqueue=enqueue,
        .print=print,
        .dequeue=dequeue,
        .peek=peek,
        .isEmpty=isEmpty,
        .isFull=isFull};
    queue.arr = malloc(queue.capacity * sizeof *queue.arr);
    Queue *ptr_queue = &queue;

    queue.enqueue(ptr_queue,1);
    queue.enqueue(ptr_queue,2);
    queue.enqueue(ptr_queue,3);
    queue.enqueue(ptr_queue,4);
    queue.enqueue(ptr_queue,5);

    queue.dequeue(ptr_queue);

    queue.enqueue(ptr_queue,6);

    queue.dequeue(ptr_queue);

    queue.enqueue(ptr_queue,7);

    queue.dequeue(ptr_queue);

    queue.enqueue(ptr_queue,8);

    queue.dequeue(ptr_queue);

    // queue.enqueue(ptr_queue,9);

    queue.print(ptr_queue);

    printf("size = %d, cap = %d,first = %d ,rear = %d ,size%%cap = %d\n",queue.size,queue.capacity,queue.first,queue.rear,(queue.size+queue.rear)%queue.capacity);

    free(queue.arr);
    return 0;
}

static void print(Queue *self){
    printf("[");
    // circular logic
    for (int i = 0; i < self->size; i++) {
        int idx = (self->first + i) % self->capacity;
        printf((i < self->size - 1) ? "%d, " : "%d", *(self->arr+idx));
    }
    printf("]\n");
}

static _Bool isEmpty(Queue *self){
    return self->size == 0;
}

static _Bool isFull(Queue *self){
    return self->size == self->capacity;
}

static void enqueue(Queue *self,int value){
    if (self->isFull(self)){
        printf("Queue is full. Deque this queue before adding element to it.\n");
        return;
    }
    if (self->isEmpty(self)){
        self->first = 0;
        self->rear = 0;
    }else{
        self->rear = (self->rear+1) % self->capacity;
    }
    *(self->arr+self->rear) = value;
    self->size++;
}

static int *dequeue(Queue *self){
    if (self->isEmpty(self)){
        printf("Deque is not allowed in empty queue\n");
        return NULL;
    }
    int *res = self->arr+self->first;

    if (self->size==0){
        self->first = -1;
        self->rear = -1;
    }else{
        self->first = (self->first+1) % self->capacity;
    }
    self->size--;
    return res;
}

static int *peek(Queue *self){
    if (self->isEmpty(self)){
        printf("Cannot peek from an empty queue\n");
        return NULL;
    }
    return self->arr+self->first;
}


