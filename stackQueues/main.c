#include<stdio.h>
#include "Qstack.h"

int main() {
    struct Stack stack = createStack();

    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);

    printf("Popped element: %d\n", pop(&stack)); 
    printf("Popped element: %d\n", pop(&stack)); 

    push(&stack, 4);
    push(&stack, 5);
    push(&stack, 6);


    printf("Popped element: %d\n", pop(&stack)); 
    printf("Popped element: %d\n", pop(&stack)); 

    return 0;
}