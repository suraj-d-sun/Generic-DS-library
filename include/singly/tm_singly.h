#ifndef __tm__$_tm_singly_h 
#define __tm__$_tm_singly_h 234 
#include "../tm_required.h"

struct SinglyLinkedListNode 
{
    void *data;
    struct SinglyLinkedListNode *next;
};

typedef struct SinglyLinkedList 
{
    struct SinglyLinkedListNode *head;
    struct SinglyLinkedListNode *tail;
    int count;
} SinglyLinkedList;

typedef struct SinglyLinkedListIterator 
{
    struct SinglyLinkedListNode *current;
} SinglyLinkedListIterator;

SinglyLinkedList *createSinglyLinkedList(int *success);
void addToSinglyLinkedList(SinglyLinkedList *list, void *data, int *success);
void insertInSinglyLinkedList(SinglyLinkedList *list, void *data, int index, int *success);
void *removeFromSinglyLinkedList(SinglyLinkedList *list, int index, int *success);
void clearSinglyLinkedList(SinglyLinkedList *list);
int getSizeOfSinglyLinkedList(SinglyLinkedList *list);
void *getElementFromSinglyLinkedList(SinglyLinkedList *list, int index, int *success);
void releaseSinglyLinkedList(SinglyLinkedList *list);

SinglyLinkedListIterator *getSinglyLinkedListIterator(SinglyLinkedList *list);
int hasMoreElementsInSinglyLinkedList(SinglyLinkedListIterator *iterator);
void *getNextElementFromSinglyLinkedList(SinglyLinkedListIterator *iterator, int *success);
void releaseSinglyLinkedListIterator(SinglyLinkedListIterator *iterator);

#endif
