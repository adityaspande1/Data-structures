
#include<stdio.h>
#include "QueStack.h"
int main() {
    struct Queue queue = createQueue();

    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);

    printf("Dequeued element: %d\n", dequeue(&queue)); // Outputs: 1
    printf("Dequeued element: %d\n", dequeue(&queue)); // Outputs: 2

    enqueue(&queue, 4);

    printf("Dequeued element: %d\n", dequeue(&queue)); // Outputs: 3
    printf("Dequeued element: %d\n", dequeue(&queue)); // Outputs: 4

    return 0;
}