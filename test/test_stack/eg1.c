#include <stdio.h>
#include <stdlib.h>
#include "../../include/stack/tm_stack.h"
#include "../../include/tm_required.h"

int main() 
{
    int success;
    
    Stack *stk = createStack(&success);
    if (!stk) 
    {
        printf("Unable to allocate Stack memory.\n");
        return 1;
    }

    int values[] = {100, 200, 300, 400, 500};
    
    for (int i = 0; i < sizeof(values)/sizeof(values[0]); i++) 
    {
        pushOnStack(stk, &values[i], &success);
        if (!success) 
        {
            printf("Error pushing element %d onto the stack.\n", values[i]);
            return 1;
        }
    }

    int size = getSizeOfStack(stk);
    printf("Size of stack is %d\n", size);

    int *ptr;
    while (!isStackEmpty(stk)) 
    {
        ptr = (int *)popFromStack(stk, &success);
        if (!success) {
            printf("Error popping element from the stack.\n");
            return 1;
        }
        printf("%d\n", *ptr);
    }

    releaseStack(stk);
    return 0;
}
