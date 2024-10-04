#include<stdio.h>
#include"infixpostfix.h"
int main() {
    const char* infixExpression = "3 + 4 * 2 - 6 / 2"; // Example infix expression
    char postfixExpression[100];

    infixToPostfix(infixExpression, postfixExpression);
    printf("Infix Expression: %s\n", infixExpression);
    printf("Postfix Expression: %s\n", postfixExpression);

    double result = evaluatePostfix(postfixExpression);
    printf("Result: %lf\n", result);

    return 0;
}
