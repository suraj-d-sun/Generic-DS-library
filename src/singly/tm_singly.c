#include <stdio.h>
#include <stdlib.h>
#include "../../include/singly/tm_singly.h"

SinglyLinkedList *createSinglyLinkedList(int *success) 
{
    if (success) *success = 0;
    SinglyLinkedList *list = (SinglyLinkedList *)malloc(sizeof(SinglyLinkedList));
    if (!list) return NULL;

    list->head = NULL;
    list->tail = NULL;
    list->count = 0;

    if (success) *success = 1;
    return list;
}

void addToSinglyLinkedList(SinglyLinkedList *list, void *data, int *success) 
{
    if (success) *success = 0;
    if (!list) return;

    struct SinglyLinkedListNode *newNode = (struct SinglyLinkedListNode *)malloc(sizeof(struct SinglyLinkedListNode));
    if (!newNode) return;

    newNode->data = data;
    newNode->next = NULL;

    if (!list->head) 
    {
        list->head = list->tail = newNode;
    } 
    else 
    {
        list->tail->next = newNode;
        list->tail = newNode;
    }
    list->count++;
    if (success) *success = 1;
}

void *getElementFromSinglyLinkedList(SinglyLinkedList *list, int index, int *success) 
{
    if (success) *success = 0;
    if (!list || index < 0 || index >= list->count) return NULL;

    struct SinglyLinkedListNode *current = list->head;
    for (int i = 0; i < index; i++) 
    {
        current = current->next;
    }

    if (success) *success = 1;
    return current->data;
}

void releaseSinglyLinkedList(SinglyLinkedList *list) 
{
    if (!list) return;

    struct SinglyLinkedListNode *current = list->head;
    while (current) 
    {
        struct SinglyLinkedListNode *next = current->next;
        free(current);
        current = next;
    }

    free(list);
}

SinglyLinkedListIterator *getSinglyLinkedListIterator(SinglyLinkedList *list) 
{
    if (!list) return NULL;

    SinglyLinkedListIterator *iterator = (SinglyLinkedListIterator *)malloc(sizeof(SinglyLinkedListIterator));
    if (!iterator) return NULL;

    iterator->current = list->head;
    return iterator;
}

int hasMoreElementsInSinglyLinkedList(SinglyLinkedListIterator *iterator) 
{
    return iterator && iterator->current;
}

void *getNextElementFromSinglyLinkedList(SinglyLinkedListIterator *iterator, int *success) 
{
    if (success) *success = 0;
    if (!iterator || !iterator->current) return NULL;

    void *data = iterator->current->data;
    iterator->current = iterator->current->next;

    if (success) *success = 1;
    return data;
}

void releaseSinglyLinkedListIterator(SinglyLinkedListIterator *iterator) 
{
    if (iterator) free(iterator);
}

void insertInSinglyLinkedList(SinglyLinkedList *list, void *data, int index, int *success) 
{
    if (success) *success = 0;
    if (!list || index < 0 || index > list->count) return;

    struct SinglyLinkedListNode *newNode = (struct SinglyLinkedListNode *)malloc(sizeof(struct SinglyLinkedListNode));
    if (!newNode) return;

    newNode->data = data;

    if (index == 0) 
    {
        newNode->next = list->head;
        list->head = newNode;
        if (!list->tail) list->tail = newNode;
    } 
    else 
    {
        struct SinglyLinkedListNode *current = list->head;
        for (int i = 0; i < index - 1; i++) 
        {
            current = current->next;
        }

        newNode->next = current->next;
        current->next = newNode;
        if (current == list->tail) list->tail = newNode;
    }

    list->count++;
    if (success) *success = 1;
}

void *removeFromSinglyLinkedList(SinglyLinkedList *list, int index, int *success) 
{
    if (success) *success = 0;
    if (!list || index < 0 || index >= list->count) return NULL;

    struct SinglyLinkedListNode *toDelete = NULL;
    void *data = NULL;

    if (index == 0) 
    {
        toDelete = list->head;
        list->head = toDelete->next;
        if (!list->head) list->tail = NULL;
    }
    else 
    {
        struct SinglyLinkedListNode *current = list->head;
        for (int i = 0; i < index - 1; i++) 
        {
            current = current->next;
        }

        toDelete = current->next;
        current->next = toDelete->next;
        if (toDelete == list->tail) list->tail = current;
    }

    data = toDelete->data;
    free(toDelete);
    list->count--;

    if (success) *success = 1;
    return data;
}

void clearSinglyLinkedList(SinglyLinkedList *list) 
{
    if (!list) return;

    struct SinglyLinkedListNode *current = list->head;
    while (current) 
    {
        struct SinglyLinkedListNode *next = current->next;
        free(current);
        current = next;
    }

    list->head = list->tail = NULL;
    list->count = 0;
}

int getSizeOfSinglyLinkedList(SinglyLinkedList *list) 
{
    return list ? list->count : 0;
}
