
#include <stdio.h> 
#include <stdlib.h> 
#include <../../include/singly/tm_singly.h> 
#include <../../include/queue/tm_queue.h> 

Queue *createQueue(int *success) 
{
    if (success) *success = 0;
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    if (queue == NULL) return NULL;

    int tempSuccess;
    queue->list = createSinglyLinkedList(&tempSuccess);
    if (!tempSuccess) 
    {
        free(queue);
        return NULL;
    }
    if (success) *success = 1;
    return queue;
}

void releaseQueue(Queue *queue) 
{
    if (queue == NULL) return;
    releaseSinglyLinkedList(queue->list);
    free(queue);
}

void clearQueue(Queue *queue) 
{
    if (queue == NULL) return;
    clearSinglyLinkedList(queue->list);
}

void enqueue(Queue *queue, void *ptr, int *success) 
{
    if (success) *success = 0;
    if (queue == NULL) return;
    addToSinglyLinkedList(queue->list, ptr, success);
}

void *dequeue(Queue *queue, int *success) 
{
    if (success) *success = 0;
    if (queue == NULL || isQueueEmpty(queue)) return NULL;
    return removeFromSinglyLinkedList(queue->list, 0, success);
}

int isQueueEmpty(Queue *queue) 
{
    if (queue == NULL) return 1;
    return getSizeOfSinglyLinkedList(queue->list) == 0;
}

void *peekQueue(Queue *queue, int *success) 
{
    if (success) *success = 0;
    if (queue == NULL || isQueueEmpty(queue)) return NULL;
    if (success) *success = 1;
    return getElementFromSinglyLinkedList(queue->list, 0, success);
}

int getSizeOfQueue(Queue *queue) 
{
    if (queue == NULL) return 0;
    return getSizeOfSinglyLinkedList(queue->list);
}
