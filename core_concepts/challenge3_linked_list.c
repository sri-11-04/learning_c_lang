/* 
🔹 Challenge 3: Singly Linked List using Pointers

Goal:
Implement a singly linked list that supports common operations — insertions, deletions, search, and traversal.

🧩 Description

A linked list is a linear data structure where each element (called a node) contains:

a data field (integer for now), and

a pointer to the next node in the list.

Unlike arrays, linked lists are dynamic — they grow/shrink during runtime using malloc/free.

🧠 Operations to Implement

insertAtBeginning(int value)
→ Add a new node at the start.

insertAtEnd(int value)
→ Add a new node at the end.

insertAtPosition(int value, int pos)
→ Insert at a specific position (1-based index).

deleteAtPosition(int pos)
→ Remove node from a specific position.

search(int value)
→ Find and print position if value exists.

display()
→ Print all nodes in [a -> b -> c -> NULL] format.

⚙️ Requirements

Use a struct Node with:

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Use a struct LinkedList to wrap it (like your Stack/Queue):

typedef struct LinkedList {
    Node *head;
    void (*insertAtBeginning)(struct LinkedList *, int);
    ...
} LinkedList;

Handle all edge cases:

Empty list insert/delete

Invalid position

Memory allocation failures

🎯 Bonus (after base version works):

Implement a reverse() function.

Add destroy() to free all nodes.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
typedef struct LinkedList LinkedList;

static void insertAtBeginning(LinkedList *self,int value);
static void insertAtEnd(LinkedList *self,int value);
static void insertAtPosition(LinkedList *self,int index,int value);
static void deleteAtPosition(LinkedList *self,int index);
static int search(LinkedList *self,int t);
static void display(LinkedList *self);
static void clear(LinkedList *self);
static _Bool isEmpty(LinkedList *self);

struct Node{
    int value;
    Node *next;
};

struct LinkedList{
    Node *head;
    int size;
    void (*insertAtBeginning)(LinkedList *self,int value);
    void (*insertAtEnd)(LinkedList *self,int value);
    void (*insertAtPosition)(LinkedList *self,int index,int value);
    void (*deleteAtPosition)(LinkedList *self,int index);
    int (*search)(LinkedList *self,int t);
    void (*display)(LinkedList *self);
    void (*clear)(LinkedList *self);
    _Bool (*isEmpty)(LinkedList *self);
};

int main(){
    LinkedList ll = {
        .head = NULL,
        .size = 0,
        .clear = clear,
        .deleteAtPosition = deleteAtPosition,
        .display = display,
        .insertAtBeginning = insertAtBeginning,
        .insertAtEnd = insertAtEnd,
        .insertAtPosition = insertAtPosition,
        .isEmpty = isEmpty,
        .search = search
    };
    LinkedList *llPtr = &ll;
    ll.insertAtEnd(llPtr,0);
    ll.insertAtBeginning(llPtr,1);
    ll.insertAtBeginning(llPtr,2);
    ll.insertAtBeginning(llPtr,3);
    ll.insertAtEnd(llPtr,-1);
    ll.insertAtBeginning(llPtr,4);
    ll.insertAtPosition(llPtr,6,-2);
    ll.insertAtPosition(llPtr,2,-3);
    ll.deleteAtPosition(llPtr,2);
    ll.deleteAtPosition(llPtr,3);
    ll.insertAtPosition(llPtr,2,4);
    ll.display(llPtr);
    printf("size = %d\n",llPtr->size);
    int target = -1;
    printf("index of the value %d is %d\n",target,ll.search(llPtr,target));
    ll.clear(llPtr);
    printf("size = %d\n",llPtr->size);
    return 0;
}

void insertAtEnd(LinkedList *self,int value){
    Node *newNode = malloc(sizeof *newNode);
    if (self->isEmpty(self)){
        self->insertAtBeginning(self,value);
        free(newNode);
    }else{
        newNode->value = value;
        newNode->next = NULL;
        Node *temp = self->head;
        while(temp->next){
            temp = temp->next;
        }
        temp->next = newNode;
        self->size++;
    }
}

void insertAtPosition(LinkedList *self,int idx,int value){
    if (idx > self->size+1 || idx <= 0){
        printf("Error : Linked List Index out of range [Line:%d]\n",__LINE__);
    }else if(idx == 1){
        self->insertAtBeginning(self,value);
    }else if(idx == self->size+1){
        self->insertAtEnd(self,value);
    }else{
        Node *temp = self->head;
        Node *newNode = malloc(sizeof *newNode);
        if (!newNode){
            printf("Error creating memory [Line:%d]\n",__LINE__);
            return;
        }
        for(int i = 1;i<idx-1;i++){
            temp=temp->next;
        }
        newNode->value = value;
        newNode->next = temp->next;
        temp->next = newNode;
        self->size++;
    }
}

int search(LinkedList *self,int t){
    /* return the index (1 based index) if the value is in the LinkedList else return -1 */
    Node *temp = self->head;
    int idx = 1;
    while(temp){
        if (temp->value == t) return idx;
        idx++;
        temp = temp->next;
    }
    return -1;
}

void deleteAtPosition(LinkedList *self,int idx){
    if (idx > self->size || idx <= 0){
        printf("Error : Linked List Index out of range [Line:%d]\n",__LINE__);
        return;
    }
    if (idx == 1){
        Node *temp = self->head->next;
        free(self->head);
        self->head = temp;
    }else{
        Node *temp = self->head;
        for (int i =1;i<idx-1;i++){
            temp=temp->next;
        }
        Node *next = temp->next->next;
        free(temp->next);
        temp->next=next;
    }
    if (!--self->size){
        self->head = NULL;
    }
}

void display(LinkedList *self){
    if (self->isEmpty(self)){
        printf("[EMPTY]\n");
        return;
    }
    Node *temp = self->head;
    printf("[");
    for (int i = 0; i<self->size;i++){
        printf((i<self->size-1)?"%d, ":"%d",temp->value);
        temp = temp->next;
    }
    printf("]\n");
}

void clear(LinkedList *self){
    while(self->head){
        Node *next = self->head->next;
        free(self->head);
        self->head = next;
    }
    self->head=NULL;
    self->size=0;
}

void insertAtBeginning(LinkedList *self,int value){
    Node *temp = malloc(sizeof *temp);
    if (!temp){
        printf("Error creating memory [Line:%d]\n",__LINE__);
        return;
    }
    if (isEmpty(self)){
        temp->value = value;
        temp->next = NULL;
        self->head = temp;
    }else{
        temp->value = value;
        temp->next = self->head;
        self->head = temp;
    }
    self->size++;
}

_Bool isEmpty(LinkedList *self){
    return self->size == 0;
}