#include <stdio.h>
#include <string.h>

#define MAX 50

struct CStack {
    int MAXSIZE;
    char stk[MAX];
    int top;
};

void createStack(struct CStack *s, int msize) {
    s->top = -1;
    s->MAXSIZE = msize;
}

int isFull(struct CStack s) {
    if (s.top == s.MAXSIZE - 1) {
        printf("Stack Overflow\n");
        return 1;
    }
    return 0;
}

int push(struct CStack *s, int elem) {
    if (isFull(*s)) {
        return -1;
    }
    s->top++;
    s->stk[s->top] = elem;
    return 1;
}

int isEmpty(struct CStack s) {
    if (s.top == -1) {
        printf("Stack underflow\n");
        return 1;
    }
    return 0;
}

int pop(struct CStack *s) {
    int data = -1;
    if (isEmpty(*s)) {
        return data;
    } else {
        data = s->stk[s->top];
        s->top--;
        return data; // returning popped element
    }
}

int peek(struct CStack s) {
    if (isEmpty(s)) {
        return -1;
    } else {
        return s.stk[s.top];
    }
}

int isOpeningBracket(char a) {
    switch (a) {
        case '[':
        case '(':
        case '{':
            return 1;
        default:
            return 0;
    }
}

int isClosingBracket(char a) {
    switch (a) {
        case ']':
        case ')':
        case '}':
            return 1;
        default:
            return 0;
    }
}

int match(char a, char b) {
    if (a == '(' && b == ')') {
        return 1;
    }
    if (a == '[' && b == ']') {
        return 1;
    }
    if (a == '{' && b == '}') {
        return 1;
    }
    return 0;
}

int isBalanced(char sm[]) {
    struct CStack ps;
    createStack(&ps, strlen(sm));
    int i = 0;
    while (sm[i] != '\0') {
        if (isOpeningBracket(sm[i])) {
            push(&ps, sm[i]);
            i++;
            continue;
        }
        if (isClosingBracket(sm[i])) {
            if (!(match(pop(&ps), sm[i]))) {
                return 0;
            }
        }
        i++;
    }
    if (isEmpty(ps)) {
        return 1;
    }
    return 0;
}
