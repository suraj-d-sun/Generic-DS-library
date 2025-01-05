#include <stdlib.h>
#include "../../include/doubly/tm_doubly.h"

DoublyLinkedList *createDoublyLinkedList() 
{
    DoublyLinkedList *list = (DoublyLinkedList *)malloc(sizeof(DoublyLinkedList));
    if (!list) return NULL;
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

void addToDoublyLinkedList(DoublyLinkedList *list, void *data, bool *success) 
{
    if (!list) 
    {
        if (success) *success = false;
        return;
    }

    DLLNode *node = (DLLNode *)malloc(sizeof(DLLNode));
    if (!node) 
    {
        if (success) *success = false;
        return;
    }

    node->data = data;
    node->next = NULL;
    node->prev = list->tail;

    if (!list->head) 
    {
        list->head = node;
    } 
    else 
    {
        list->tail->next = node;
    }

    list->tail = node;
    list->size++;
    if (success) *success = true;
}

void insertInDoublyLinkedList(DoublyLinkedList *list, void *data, int index, bool *success) 
{
    if (!list || index < 0 || index > list->size) 
    {
        if (success) *success = false;
        return;
    }

    DLLNode *node = (DLLNode *)malloc(sizeof(DLLNode));
    if (!node) 
    {
        if (success) *success = false;
        return;
    }

    node->data = data;
    if (index == 0)  // Insert at the head
    {
        node->next = list->head;
        node->prev = NULL;
        if (list->head) list->head->prev = node;
        list->head = node;
        if (!list->tail) list->tail = node;  // If list was empty
    } 
    else if (index == list->size) // Insert at the tail
    {   node->next = NULL;
        node->prev = list->tail;
        list->tail->next = node;
        list->tail = node;
    } 
    else // Insert in the middle 
    {   
        DLLNode *current = list->head;
        for (int i = 0; i < index; i++) 
        {
            current = current->next;
        }
        node->next = current;
        node->prev = current->prev;
        current->prev->next = node;
        current->prev = node;
    }

    list->size++;
    if (success) *success = true;
}

void *removeFromDoublyLinkedList(DoublyLinkedList *list, int index, bool *success) 
{
    if (!list || index < 0 || index >= list->size) 
    {
        if (success) *success = false;
        return NULL;
    }

    DLLNode *node = list->head;
    for (int i = 0; i < index; i++) 
    {
        node = node->next;
    }

    void *data = node->data;

    if (node->prev) 
    {
        node->prev->next = node->next;
    } 
    else 
    {
        list->head = node->next;
    }

    if (node->next) 
    {
        node->next->prev = node->prev;
    } 
    else 
    {
        list->tail = node->prev;
    }

    free(node);
    list->size--;
    if (success) *success = true;
    return data;
}

void clearDoublyLinkedList(DoublyLinkedList *list) 
{
    if (!list) return;
    DLLNode *current = list->head;
    while (current) 
    {
        DLLNode *next = current->next;
        free(current);
        current = next;
    }

    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

int getSizeOfDoublyLinkedList(const DoublyLinkedList *list) 
{
    return list ? list->size : 0;
}

void *getElementFromDoublyLinkedList(const DoublyLinkedList *list, int index, bool *success) 
{
    if (!list || index < 0 || index >= list->size) 
    {
        if (success) *success = false;
        return NULL;
    }

    DLLNode *current = list->head;
    for (int i = 0; i < index; i++) 
    {
        current = current->next;
    }

    if (success) *success = true;
    return current->data;
}

void releaseDoublyLinkedList(DoublyLinkedList *list) 
{
    if (!list) return;
    clearDoublyLinkedList(list);
    free(list);
}

DoublyLinkedListIterator *createDoublyLinkedListIterator(const DoublyLinkedList *list, IteratorDirection direction) 
{
    if (!list || (direction != FORWARD && direction != BACKWARD)) return NULL;

    DoublyLinkedListIterator *iterator = (DoublyLinkedListIterator *)malloc(sizeof(DoublyLinkedListIterator));
    if (!iterator) return NULL;

    iterator->direction = direction;
    iterator->current = (direction == FORWARD) ? list->head : list->tail;
    return iterator;
}

bool hasMoreElements(DoublyLinkedListIterator *iterator) 
{
    return iterator && iterator->current != NULL;
}

void *getNextElement(DoublyLinkedListIterator *iterator, bool *success) 
{
    if (!iterator || !iterator->current) 
    {
        if (success) *success = false;
        return NULL;
    }

    void *data = iterator->current->data;
    iterator->current = (iterator->direction == FORWARD) ? iterator->current->next : iterator->current->prev;

    if (success) *success = true;
    return data;
}

void releaseDoublyLinkedListIterator(DoublyLinkedListIterator *iterator) 
{
    if (iterator) free(iterator);
}
