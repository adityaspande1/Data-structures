#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 50


struct Stack {
    int top;
    int array[MAX_SIZE];
};


struct Stack createStack() {
    struct Stack stack;
    stack.top = -1;
    return stack;
}


int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}


int isFull(struct Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}


void push(struct Stack* stack, int item) {
    if (isFull(stack)) {
        printf("Stack is full. Cannot push.\n");
        return;
    }
    stack->array[++stack->top] = item;
}


int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot pop.\n");
        return -1; 
    }
    return stack->array[stack->top--];
}

// Structure for implementing a queue using two stacks
struct Queue {
    struct Stack stack1;
    struct Stack stack2;
};


struct Queue createQueue() {
    struct Queue queue;
    queue.stack1 = createStack();
    queue.stack2 = createStack();
    return queue;
}


void enqueue(struct Queue* queue, int item) {
    while (!isEmpty(&(queue->stack1))) {
        push(&(queue->stack2), pop(&(queue->stack1)));
    }
    push(&(queue->stack1), item);
    while (!isEmpty(&(queue->stack2))) {
        push(&(queue->stack1), pop(&(queue->stack2)));
    }
}


int dequeue(struct Queue* queue) {
    if (isEmpty(&(queue->stack1))) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1; // You can choose an appropriate error value.
    }
    return pop(&(queue->stack1));
}


