#include <stdio.h>
#include <stdlib.h>
#include "../../include/queue/tm_queue.h"
#include "../../include/singly/tm_singly.h"
#include "../../include/tm_required.h"

int main()
{
    int success;

    Queue *que = createQueue(&success);
    if (!que)
    {
        printf("Unable to allocate Queue memory.\n");
        return 0;
    }

    int num1 = 100, num2 = 200, num3 = 300, num4 = 400, num5 = 500;

    enqueue(que, &num1, &success);
    if (!success) printf("Failed to push %d onto queue\n", num1);

    enqueue(que, &num2, &success);
    if (!success) printf("Failed to push %d onto queue\n", num2);

    enqueue(que, &num3, &success);
    if (!success) printf("Failed to push %d onto queue\n", num3);

    enqueue(que, &num4, &success);
    if (!success) printf("Failed to push %d onto queue\n", num4);

    enqueue(que, &num5, &success);
    if (!success) printf("Failed to push %d onto queue\n", num5);

    int size = getSizeOfQueue(que);
    printf("Size of the queue is: %d\n", size);

    printf("Elements in the queue:\n");
    while (!isQueueEmpty(que))
    {
        int *ptr = (int *)dequeue(que, &success);
        if (success) printf("%d\n", *ptr);
        else printf("Error popping element from the queue\n");
    }

    releaseQueue(que);
    return 0;
}
