#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


// Define a structure for a stack
struct Stack {
    int top;
    char array[100];
};

// Create a new stack
struct Stack createStack() {
    struct Stack stack;
    stack.top = -1;
    return stack;
}

// Check if the stack is empty
int  isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Push an element onto the stack
void push(struct Stack* stack, char item) {
    stack->array[++stack->top] = item;
}

// Pop an element from the stack and return its value
char pop(struct Stack* stack) {
    return stack->array[stack->top--];
}

// Function to determine the precedence of an operator
int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    } else if (op == '*' || op == '/') {
        return 2;
    }
    return 0;
}

// Convert an infix expression to a postfix expression
void infixToPostfix(const char* infix, char* postfix) {
    struct Stack operatorStack = createStack();
    int postfixIndex = 0;

    for (int i = 0; infix[i]; i++) {
        if (isdigit(infix[i])) {
            postfix[postfixIndex++] = infix[i];
        } else if (infix[i] == ' ') {
            continue; // Skip whitespace
        } else {
            while (!isEmpty(&operatorStack) && precedence(operatorStack.array[operatorStack.top]) >= precedence(infix[i])) {
                postfix[postfixIndex++] = pop(&operatorStack);
            }
            push(&operatorStack, infix[i]);
        }
    }

    while (!isEmpty(&operatorStack)) {
        postfix[postfixIndex++] = pop(&operatorStack);
    }

    postfix[postfixIndex] = '\0'; // Null-terminate the postfix expression
}

// Function to evaluate a postfix expression
double evaluatePostfix(const char* postfix) {
    struct Stack operandStack = createStack();

    for (int i = 0; postfix[i]; i++) {
        if (isdigit(postfix[i])) {
            push(&operandStack, postfix[i] - '0');
        } else {
            double num2 = pop(&operandStack);
            double num1 = pop(&operandStack);
            switch (postfix[i]) {
                case '+':
                    push(&operandStack, num1 + num2);
                    break;
                case '-':
                    push(&operandStack, num1 - num2);
                    break;
                case '*':
                    push(&operandStack, num1 * num2);
                    break;
                case '/':
                    push(&operandStack, num1 / num2);
                    break;
                default:
                    printf("Error: Invalid operator\n");
                    exit(1);
            }
        }
    }

    return pop(&operandStack);
}

