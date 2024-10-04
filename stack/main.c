#include<stdio.h>
#include "stack.h"

int main(){
// printf("Hello World!");
struct Stack array;
struct Stack array1;
struct Stack arrayt;
init(&array,10);
init(&array1,10);
push(&array,1);
push(&array,2);
push(&array,3);
push(&array,4);
push(&array1,1);
push(&array1,2);
push(&array1,3);
push(&array1,4);

printf("The stack is \n");
print(array);
// pop(&array);
merge(array,array1,&arrayt);
printf("\n");
print(arrayt);
return 0;
}