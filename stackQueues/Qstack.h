#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

//structure for Queue.
struct Queue {
    int front, rear, size;
    unsigned capacity;
    int array[MAX_SIZE];
};
//structure for stack.
struct Stack {
    //the structure will use two queues for the implementation of this stack.
    struct Queue q1;
    struct Queue q2;
};

struct Queue createQueue() {
    struct Queue queue;
    queue.capacity = MAX_SIZE;
    queue.front = queue.size = 0;
    queue.rear = MAX_SIZE - 1; 
    return queue;
}


int isEmpty(struct Queue* queue) {
    return (queue->size == 0);
}


int isFull(struct Queue* queue) {
    return (queue->size == queue->capacity);
}


void enqueue(struct Queue* queue, int item) {
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
}


int dequeue(struct Queue* queue) {
    if (isEmpty(queue))
        return -1; 
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}




struct Stack createStack() {
    struct Stack stack;
    stack.q1 = createQueue();
    stack.q2 = createQueue();
    return stack;
}


void push(struct Stack* stack, int item) {
    if (isEmpty(&(stack->q1))) {
        enqueue(&(stack->q1), item);
    } else {
        while (!isEmpty(&(stack->q1))) {
            enqueue(&(stack->q2), dequeue(&(stack->q1)));
        }
        enqueue(&(stack->q1), item);
        while (!isEmpty(&(stack->q2))) {
            enqueue(&(stack->q1), dequeue(&(stack->q2)));
        }
    }
}


int pop(struct Stack* stack) {
    if (isEmpty(&(stack->q1)))
        return -1; 
    return dequeue(&(stack->q1));
}


