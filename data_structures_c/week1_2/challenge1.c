#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
typedef struct LinkedList LinkedList;
typedef enum Type Type;
typedef union Type_ Type_;

static void str(LinkedList *self);
static void append(LinkedList *self,void *value);
static void insert(LinkedList *self,int index,void *value);
static void *pop(LinkedList *self,int index);
static void llRemove(LinkedList *self,void *value);
static void clear(LinkedList *self);
static void convertValue(LinkedList *ll,Node *node,void *val);
static _Bool findValue(LinkedList *self,Type_ *data,void *val);


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

struct Node {
    Type_ data;
    Node *next;
};

struct LinkedList{
    Type type;
    Node *head;
    int size;
    void (*str)(LinkedList *self);
    void (*append)(LinkedList *self,void *value);
    void (*insert)(LinkedList *self,int index,void *value);
    void *(*pop)(LinkedList *self,int index);
    void (*remove)(LinkedList *self,void *value);
    void (*clear)(LinkedList *self);
    _Bool (*_findValue)(LinkedList *self,Type_ *data,void *value);
};

int main (void){
    int rem;
    LinkedList ll = {
        .type = INT,
        .head = NULL,
        .size = 0,
        .str = str,
        .append = append,
        .insert = insert,
        .pop = pop,
        .remove = llRemove,
        .clear = clear,
        ._findValue = findValue
    };
    LinkedList *llPtr = &ll;
    int data;

    data = 1;
    ll.append(llPtr,&data);

    data = 2;
    ll.append(llPtr,&data);

    data = 3;
    ll.append(llPtr,&data);

    int res = *(int *) ll.pop(llPtr,-1);

    printf("value returned from the pop is %d\n",res);

    data = 0;
    ll.insert(llPtr,1,&data);

    rem = 2;
    ll.remove(llPtr,&rem);

    // ll.remove(llPtr,&rem);

    data = 4;
    ll.append(llPtr,&data);

    ll.str(llPtr);

    printf("size of the ll is %d\n",ll.size);

    ll.clear(llPtr);
    return 0;
}

void str(LinkedList *self){
    printf("Linked List: ");
    Node *temp = self->head;
    while (temp){
        switch (self->type){
            case 0:
                printf("%d -> ",temp->data.iVal);
                break;
            case 1:
                printf("%.2f -> ",temp->data.fVal);
                break;
            case 2:
                printf("%c -> ",temp->data.cVal);
                break;
        }
        temp = temp->next;
    }
    printf("NULL\n");
}

void append(LinkedList *self,void *value){
    Node *newNode = malloc(sizeof *newNode);
    if (!newNode){
        perror("Error while allocating memory\nclearing memory and exiting script.");
        self->clear(self);
        exit(1);
    } 
    convertValue(self,newNode,value);
    newNode->next = NULL;
    if (self->head == NULL)
        self->head = newNode;
    else{
        Node *temp = self->head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }
    self->size+=1;
}

void clear(LinkedList *self){
    Node *temp = self->head;
    while (temp){
        Node *tempp = temp->next;
        free(temp);
        temp = tempp;
    }
    self->head = NULL;
    self->size = 0;
}

void insert(LinkedList *self,int index,void *value){
    if (index > self->size || index < 0){
        printf("Index %d is out of range for a %d sized ll\n",index,self->size);
        return;
    }
    if (index == self->size){
        self->append(self,value);
        return;
    }
    Node *newNode = malloc(sizeof *newNode);
    if (!newNode){
        perror("Error while allocating memory\nclearing memory and exiting script.");
        self->clear(self);
        exit(1);
    }
    convertValue(self,newNode,value);
    if (index == 0){
        newNode->next = self->head;
        self->head = newNode;
    }else{
        Node *temp = self->head;
        for (int i = 0;i<index-1;i++)
            temp = temp->next;
        newNode->next = temp->next;
        temp->next = newNode;
    }
    self->size++;
}

void *pop(LinkedList *self,int index){
    if (self->size==0){
        printf("Linked list has no element to pop\n");
        return NULL;
    }else if (index >= self->size || index < -1){
        printf("Index %d is out of range for a %d sized ll\n",index,self->size);
        return NULL;
    }
    index = (index != -1) ? index : self->size-1;
    Node *temp = self->head;
    Type_ res;
    if (index != 0){
        for (int i = 0;i<index-1;i++)
            temp = temp->next;
        switch(self->type){
            case 0:
                res.iVal = temp->next->data.iVal;
                break;
            case 1:
                res.fVal = temp->next->data.fVal;
                break;
            case 2:
                res.cVal = temp->next->data.cVal;
                break;
        }
        Node *tempp = temp->next->next;
        free(temp->next);
        temp->next = tempp;
    }else{
        Node *tempp = temp->next;
        free(self->head);
        self->head = tempp;
    }
    
    self->size--; 
    return (self->type == INT) ? (void*)&res.iVal : (self->type == FLOAT) ? (void*)&res.fVal : (void*)&res.cVal;
}

void llRemove(LinkedList *self,void *value){
    if (self->head == NULL){
        printf("Error : removing from an empty ll\n");
        return;
    }
    Node *temp = self->head, *prev=NULL;
    while(temp && !self->_findValue(self,&temp->data,value)){
        prev = temp;
        temp = temp->next;
    }
    if (!temp){
        printf("Given value is not in the ll\n");
        return;
    }
    if (!prev)
        self->head = self->head->next;
    else
        prev->next = temp->next;
    
    free(temp);
    self->size--;
}

void convertValue(LinkedList *ll,Node *node,void *value){
    switch(ll->type){
            case 0:
                node->data.iVal = *(int*) value;
                break;
            case 1:
                node->data.fVal = *(float*) value;
                break;
            case 2:
                node->data.cVal = *(char*) value;
                break;
        }
}

_Bool findValue(LinkedList *self,Type_ *data,void *value){
    switch(self->type){
        case 0:
            return data->iVal == *(int*) value;
        case 1:
            return data->fVal == *(float*) value;
        case 2:
            return data->cVal == *(char*) value;
        default:
            return 0;
    }
}



