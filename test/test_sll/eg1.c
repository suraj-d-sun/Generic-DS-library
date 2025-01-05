#include <stdio.h>
#include <stdlib.h>
#include "../../include/singly/tm_singly.h"
#include "../../include/tm_required.h"

int main() 
{
    int success;
    SinglyLinkedList *sll;
    
    sll = createSinglyLinkedList(&success);
    if (!success) 
    {
        printf("Unable to allocate memory for singly linked list\n");
        return 1;
    }

    int values[] = {100, 200, 300, 400, 500};
    
    for (int i = 0; i < sizeof(values)/sizeof(values[0]); i++) 
    {
        addToSinglyLinkedList(sll, &values[i], &success);
        if (!success) 
        {
            printf("Error adding element %d to the list\n", values[i]);
            return 1;
        }
    }

    SinglyLinkedListIterator *iterator = getSinglyLinkedListIterator(sll);
    if (iterator == NULL) 
    {
        printf("Error initializing iterator\n");
        return 1;
    }

    while (hasMoreElementsInSinglyLinkedList(iterator)) 
    {
        int *element = (int *)getNextElementFromSinglyLinkedList(iterator, &success);
        if (!success) 
        {
            printf("Error retrieving element from the list\n");
            return 1;
        }
        printf("%d\n", *element);
    }

    releaseSinglyLinkedListIterator(iterator);
    releaseSinglyLinkedList(sll);

    return 0;
}
