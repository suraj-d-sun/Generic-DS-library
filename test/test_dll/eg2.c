#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "tm_doubly.h" 

struct Name 
{
    char firstName[30];
    char lastName[30];
};

struct Address 
{
    char street[50];
    char city[30];
    char country[30];
};

struct Person 
{
    struct Name name;
    struct Address *address;
    int age;
};

struct Person *createPerson(const char *firstName, const char *lastName, const char *street, const char *city, const char *country, int age) 
{
    struct Person *p = (struct Person *)malloc(sizeof(struct Person));
    if (!p) return NULL;
    
    strncpy(p->name.firstName, firstName, sizeof(p->name.firstName) - 1);
    strncpy(p->name.lastName, lastName, sizeof(p->name.lastName) - 1);
    
    p->address = (struct Address *)malloc(sizeof(struct Address));
    if (!p->address) 
    {
        free(p);
        return NULL;
    }
    strncpy(p->address->street, street, sizeof(p->address->street) - 1);
    strncpy(p->address->city, city, sizeof(p->address->city) - 1);
    strncpy(p->address->country, country, sizeof(p->address->country) - 1);
    
    p->age = age;
    return p;
}

void freePerson(struct Person *p) 
{
    if (p) 
    {
        free(p->address);
        free(p); 
    }
}

int main() 
{
    bool success;
    
    DoublyLinkedList *list = createDoublyLinkedList();
    if (!list) 
    {
        printf("Failed to create list\n");
        return -1;
    }

    struct Person *p1 = createPerson("Amit", "Sharma", "50, Nanda Nagar", "Indore", "India", 30);
    if (!p1) 
    {
        printf("Failed to create person\n");
        return -1;
    }
    
    addToDoublyLinkedList(list, p1, &success);
    if (!success) 
    {
        freePerson(p1);
        printf("Failed to add person to list\n");
        return -1;
    }

    struct Person *p2 = createPerson("Suyash", "Rathore", "11 VN Nagar", "Indore", "India", 25);
    if (!p2) 
    {
        printf("Failed to create person\n");
        return -1;
    }

    addToDoublyLinkedList(list, p2, &success);
    if (!success) 
    {
        freePerson(p2);
        printf("Failed to add person to list\n");
        return -1;
    }

    printf("List of Persons:\n");
    DoublyLinkedListIterator *iterator = createDoublyLinkedListIterator(list, FORWARD);
    if (!iterator) 
    {
        printf("Failed to create iterator\n");
        return -1;
    }

    while (hasMoreElements(iterator)) 
    {
        struct Person *person = (struct Person *)getNextElement(iterator, &success);
        if (success) {
            printf("Name: %s %s\n", person->name.firstName, person->name.lastName);
            printf("Address: %s, %s, %s\n", person->address->street, person->address->city, person->address->country);
            printf("Age: %d\n\n", person->age);
        }
    }
    
    removeFromDoublyLinkedList(list, 0, &success);
    if (success)  printf("First person removed from the list.\n");
    else printf("Failed to remove person from list.\n");

    releaseDoublyLinkedList(list);
    freePerson(p1);
    freePerson(p2);
    releaseDoublyLinkedListIterator(iterator);

    return 0;
}
