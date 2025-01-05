#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../../include/doubly/tm_doubly.h"
#include "../../include/tm_required.h"

int main()
{
    bool success;

    DoublyLinkedList *dll = createDoublyLinkedList(&success);
    if (!success)
    {
        printf("Unable to allocate memory for Doubly Linked List\n");
        return 0;
    }

    int a1 = 100, a2 = 200, a3 = 300, a4 = 400, a5 = 500;
    addToDoublyLinkedList(dll, &a1, &success);
    if (!success) printf("Failed to add a1\n");

    addToDoublyLinkedList(dll, &a2, &success);
    if (!success) printf("Failed to add a2\n");

    addToDoublyLinkedList(dll, &a3, &success);
    if (!success) printf("Failed to add a3\n");

    addToDoublyLinkedList(dll, &a4, &success);
    if (!success) printf("Failed to add a4\n");

    addToDoublyLinkedList(dll, &a5, &success);
    if (!success) printf("Failed to add a5\n");

    DoublyLinkedListIterator *iterator = createDoublyLinkedListIterator(dll, 2);
    if (!iterator)
    {
        printf("Failed to create iterator\n");
        releaseDoublyLinkedList(dll);
        return 0;
    }

    printf("Elements from index 2:\n");
    while (hasMoreElements(iterator))
    {
        int *element = (int *)getNextElement(iterator, &success);
        if (success) printf("%d\n", *element);
        else printf("Error retrieving element\n");
    }

    releaseDoublyLinkedListIterator(iterator);
    releaseDoublyLinkedList(dll);

    return 0;
}
