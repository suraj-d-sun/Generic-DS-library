#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <stdbool.h>
#include "../tm_required.h"
typedef struct DLLNode
{
    void *data; 
    struct DLLNode *next;
    struct DLLNode *prev;
} DLLNode;

typedef struct
{
    DLLNode *head;
    DLLNode *tail;
    int size;
} DoublyLinkedList;

typedef enum
{
    FORWARD = 1,
    BACKWARD = 2
} IteratorDirection;

typedef struct
{
    DLLNode *current;
    IteratorDirection direction;
} DoublyLinkedListIterator;

DoublyLinkedList *createDoublyLinkedList();
void addToDoublyLinkedList(DoublyLinkedList *list, void *data, bool *success);
void insertInDoublyLinkedList(DoublyLinkedList *list, void *data, int index, bool *success);
void *removeFromDoublyLinkedList(DoublyLinkedList *list, int index, bool *success);
void clearDoublyLinkedList(DoublyLinkedList *list);
int getSizeOfDoublyLinkedList(const DoublyLinkedList *list);
void *getElementFromDoublyLinkedList(const DoublyLinkedList *list, int index, bool *success);
void releaseDoublyLinkedList(DoublyLinkedList *list);

DoublyLinkedListIterator *createDoublyLinkedListIterator(const DoublyLinkedList *list, IteratorDirection direction);
bool hasMoreElements(DoublyLinkedListIterator *iterator);
void *getNextElement(DoublyLinkedListIterator *iterator, bool *success);
void releaseDoublyLinkedListIterator(DoublyLinkedListIterator *iterator);

#endif
