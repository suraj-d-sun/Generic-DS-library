
#include <stdio.h>
#include <stdlib.h>
#include "../../include/singly/tm_singly.h"
#include "../../include/stack/tm_stack.h"

Stack *createStack(int *success) 
{
    Stack *stack;
    int isSuccess = 0;
    if (success) *success = 0;
    stack = (Stack *)malloc(sizeof(Stack));
    if (!stack) return NULL;
    stack->list = createSinglyLinkedList(&isSuccess);
    if (!isSuccess) 
    {
        free(stack);
        return NULL;
    }
    if (success) *success = 1;
    return stack;
}

void releaseStack(Stack *stack) 
{
    if (!stack) return;
    clearStack(stack);
    releaseSinglyLinkedList(stack->list);
    free(stack);
}

void clearStack(Stack *stack) 
{
    if (!stack) return;
    clearSinglyLinkedList(stack->list);
}

void pushOnStack(Stack *stack, void *ptr, int *success) 
{
    if (success) *success = 0;
    if (!stack) return;
    insertInSinglyLinkedList(stack->list, ptr, 0, success);
}

void *peekInStack(Stack *stack, int *success) 
{
    if (success) *success = 0;
    if (!stack) return NULL;
    return getElementFromSinglyLinkedList(stack->list, 0, success);
}

void *popFromStack(Stack *stack, int *success) 
{
    if (success) *success = 0;
    if (!stack) return NULL;
    return removeFromSinglyLinkedList(stack->list, 0, success);
}

int isStackEmpty(Stack *stack)
{
    if (!stack) return 1;
    return getSizeOfSinglyLinkedList(stack->list) == 0;
}

int getSizeOfStack(Stack *stack) 
{
    if (!stack) return 0;
    return getSizeOfSinglyLinkedList(stack->list);
}
