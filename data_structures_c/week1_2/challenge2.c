#include <stdio.h>
#include <stdlib.h>

typedef struct DoublyLinkedList DoublyLinkedList;
typedef struct Node Node;
typedef enum Type Type;
typedef union Type_ Type_;

static void append(DoublyLinkedList *self,void *val);
static void prepend(DoublyLinkedList *self,void *val);
static void insert(DoublyLinkedList *self,int index,void *val);
static void *pop(DoublyLinkedList *self,int index);
static void __str__(DoublyLinkedList *self,_Bool reverse);
static void printForward(DoublyLinkedList *self);
static void printBackward(DoublyLinkedList *self);
static void clear(DoublyLinkedList *self);
static void setData(DoublyLinkedList *self,Node *node,void *val);

enum Type{
    INT,
    FLOAT,
    CHAR
};

union Type_{
    int iVal;
    float fVal;
    char cVal;
};

struct Node{
    Type_ data;
    Node *prev;
    Node *next;
};

struct DoublyLinkedList{
    Type type;
    int size;
    Node *head;
    Node *tail;
    void (*append)(DoublyLinkedList *self,void *val);
    void (*insert)(DoublyLinkedList *self,int index,void *val);
    void (*prepend)(DoublyLinkedList *self,void *val);
    void *(*pop)(DoublyLinkedList *self,int index);
    void (*__str__)(DoublyLinkedList *self,_Bool rev);
    void (*printBackward)(DoublyLinkedList *self);
    void (*printForward)(DoublyLinkedList *self);
    void (*clear)(DoublyLinkedList *self);
    void (*setData)(DoublyLinkedList *self,Node *node,void *val);
};

int main(void){
    int data;
    DoublyLinkedList dll = {
        .head=NULL,
        .tail=NULL,
        .type=INT,
        .size = 0,
        .append = append,
        .clear= clear,
        .insert=insert,
        .pop= pop,
        .prepend=prepend,
        .printBackward=printBackward,
        .printForward=printForward,
        .setData=setData,
        .__str__ = __str__
    };
    DoublyLinkedList *self = &dll;
    printf("%p\n",self);

    data = 1;
    dll.append(self,&data);

    data = 2;
    dll.append(self,&data);

    data = 3;
    dll.append(self,&data);

    data = 4;
    dll.append(self,&data);

    dll.printForward(self);

    
    dll.clear(self);
    return 0;
}

void __str__(DoublyLinkedList *self,_Bool rev){
        Node *temp = rev ? self->tail : self->head;
        printf((rev) ? "Backward: " : "Forward: ");
        while (temp){
            switch(self->type){
                case 0:
                    printf("%d <-> ",temp->data.iVal);
                    break;
                case 1:
                    printf("%.2f <-> ",temp->data.fVal);
                    break;
                case 2:
                    printf("%c <-> ",temp->data.cVal);
                    break;
            }
            temp = (rev) ? temp->prev : temp->next;
        }
        printf("NULL\n");
}

void printForward(DoublyLinkedList *self){
    self->__str__(self,0);
}

void printBackward(DoublyLinkedList *self){
    self->__str__(self,1);
}

void append(DoublyLinkedList *self,void *val){
    Node *newNode = malloc(sizeof *newNode);
    if (newNode == NULL){
        perror("error while allocating memory to node");
        self->clear(self);
        exit(1);
    }
    self->setData(self,newNode,val);
    newNode->next = NULL;
    if (self->head == NULL){
        newNode->prev=NULL;
        self->head=newNode;
    }else{
        if (self->tail != NULL){
            newNode->prev = self->tail;
            self->tail->next = newNode;
            self->tail = newNode;
        }else{
            newNode->prev = self->head;
            self->tail = newNode;
            self->head->next = newNode;
        }
        self->size++;
    }
}

// memory is not cleared properly
void clear(DoublyLinkedList *self){
    Node *temp= self->head;
    while (temp){
        if (temp->prev) free(temp->prev);
        Node *tempp = temp->next;
        free(temp);
        temp = tempp;
    }
    self->head = NULL;
    self->size = 0;
    self->tail = NULL;
}


void setData(DoublyLinkedList *self,Node *node,void *val){
    switch (self->type){
        case 0:
            node->data.iVal = *(int *) val;
            break;
        case 1:
            node->data.fVal = *(float *) val;
            break;
        case 2:
            node->data.cVal = *(char *) val;
            break;
    }
}


void prepend(DoublyLinkedList *self,void *val){}

void insert(DoublyLinkedList *self,int index,void *val){}

void *pop(DoublyLinkedList *self,int index){}




