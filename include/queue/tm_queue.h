#ifndef __$__tm_queue_h 
#define __$__tm_queue_h 4234 
#include "../singly/tm_singly.h"
#include "../tm_required.h"

typedef struct _$_Queue 
{
    SinglyLinkedList *list;
} Queue;

Queue *createQueue(int *success);
void releaseQueue(Queue *queue);
void clearQueue(Queue *queue);
void enqueue(Queue *queue, void *ptr, int *success);
void *dequeue(Queue *queue, int *success);
int isQueueEmpty(Queue *queue);
void *peekQueue(Queue *queue, int *success);
int getSizeOfQueue(Queue *queue);

#endif
