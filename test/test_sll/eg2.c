#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <tm_required.h>
#include <tm_singly.h>

struct Student 
{
    int rollNumber;
    char *name;
};

void addStudent(SinglyLinkedList *list) 
{
    int found = 0, rollNumber, success;
    char name[22], m;
    struct Student *s;
    SinglyLinkedListIterator *ite;
    
    printf("Enter roll number: ");
    scanf("%d", &rollNumber);
    getchar();

    if (rollNumber <= 0) 
    {
        printf("Invalid roll number\n");
        return;
    }

    ite = getSinglyLinkedListIterator(list);
    while (hasMoreElementsInSinglyLinkedList(ite))
    {
        s = (struct Student *)getNextElementFromSinglyLinkedList(ite, &success);
        if (s->rollNumber == rollNumber) 
        {
            found = 1;
            break;
        }
    }

    if (found) 
    {
        printf("That roll number is already allotted to %s\n", s->name);
        return;
    }

    printf("Enter name: ");
    fgets(name, sizeof(name), stdin);
    name[strlen(name) - 1] = '\0';

    printf("Save(Y/N): ");
    m = getchar();
    if (m != 'Y' && m != 'y') 
    {
        printf("Student not added\n");
        return;
    }

    s = (struct Student *)malloc(sizeof(struct Student));
    if (s == NULL) 
    {
        printf("Unable to add student, insufficient memory\n");
        return;
    }

    s->name = (char *)malloc(sizeof(char) * (strlen(name) + 1));
    if (s->name == NULL) 
    {
        free(s);
        printf("Unable to add student, insufficient memory\n");
        return;
    }

    s->rollNumber = rollNumber;
    strcpy(s->name, name);
    addToSinglyLinkedList(list, s, &success);

    if (!success) 
    {
        free(s->name);
        free(s);
        printf("Unable to add student, insufficient memory\n");
        return;
    }

    printf("Student added\n");
}

void displayListOfStudents(SinglyLinkedList *list) 
{
    struct Student *s;
    int success;
    SinglyLinkedListIterator *iterator = getSinglyLinkedListIterator(list);

    while (hasMoreElementsInSinglyLinkedList(iterator)) 
    {
        s = (struct Student *)getNextElementFromSinglyLinkedList(iterator, &success);
        printf("%d, %s\n", s->rollNumber, s->name);
    }
}

void removeStudent(SinglyLinkedList *list) 
{
    int rollNumber, success;
    struct Student *s;
    printf("Enter roll number to remove: ");
    scanf("%d", &rollNumber);
    getchar();

    SinglyLinkedListIterator *ite = getSinglyLinkedListIterator(list);
    while (hasMoreElementsInSinglyLinkedList(ite)) 
    {
        s = (struct Student *)getNextElementFromSinglyLinkedList(ite, &success);
        if (s->rollNumber == rollNumber) 
        {
            removeFromSinglyLinkedList(list, rollNumber, &success);
            if (success) printf("Student removed\n");
            else printf("Failed to remove student\n");
            return;
        }
    }
    printf("Student not found\n");
}

int main() 
{
    int ch, success;
    struct Student *s;
    SinglyLinkedListIterator *iterator;
    SinglyLinkedList *list = createSinglyLinkedList(&success);

    if (!success) 
    {
        printf("Insufficient memory\n");
        return 0;
    }

    while (1) 
    {
        printf("1. Add\n");
        printf("2. Remove\n");
        printf("3. Display size\n");
        printf("4. List\n");
        printf("5. Clear\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        getchar();

        if (ch == 1) addStudent(list);
        if (ch == 2) removeStudent(list);
        if (ch == 3) printf("List size: %d\n", getSizeOfSinglyLinkedList(list));
        if (ch == 4) displayListOfStudents(list);
        if (ch == 5) clearSinglyLinkedList(list);
        if (ch == 6) break;
    }

    iterator = getSinglyLinkedListIterator(list);
    while (hasMoreElementsInSinglyLinkedList(iterator)) 
    {
        s = (struct Student *)getNextElementFromSinglyLinkedList(iterator, &success);
        free(s->name);
        free(s);
    }

    releaseSinglyLinkedList(list);
    return 0;
}
