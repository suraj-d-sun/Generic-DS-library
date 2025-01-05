#ifndef __$__tm_stack_h 
#define __$__tm_stack_h 4234 

#include <../../include/singly/tm_singly.h> 
#include "../tm_required.h"

typedef struct _$_Stack 
{ 
    SinglyLinkedList *list; 
} Stack; 

Stack *createStack(int *success); 
void releaseStack(Stack *stack); 
void clearStack(Stack *stack); 
void pushOnStack(Stack *stack, void *ptr, int *success); 
void *popFromStack(Stack *stack, int *success); 
int isStackEmpty(Stack *stack); 
void *peekInStack(Stack *stack, int *success); 
int getSizeOfStack(Stack *stack); 

#endif
