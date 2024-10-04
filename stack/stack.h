#include<stdio.h>
#include<stdlib.h>
#define MAX 50
struct Stack{
    int capacity;
    int stack[MAX];
    int lastIndex;
};

void init(struct Stack * arr,int maxSize){
    arr->lastIndex=-1;
    arr->capacity=maxSize;
}

int isFull(struct Stack arr){
    if(arr.lastIndex==(arr.capacity)-1){
        return 1;
    }
    return 0;
}
int isEmpty(struct Stack arr){
    if(arr.lastIndex==-1){
        return 1;
        
    }
    return 0;
}
//function to add data to the stack;
int push(struct Stack *arr,int elem){
    //case1: the array is isFull
    if(isFull(*arr)){
        printf("stack overflow\n");
        return 0;
    }else{
        //case2:not full
        (arr->lastIndex)++;
        arr->stack[arr->lastIndex]=elem;
        return 1;
    }
}
//function to print stack.
void print(struct Stack arr){
    if(arr.lastIndex==-1){
        printf("[]");
    }else{
        int i=0;
        printf("[");
        
        while(i!=arr.lastIndex+1){
            printf("%d,",arr.stack[i]);
            i++;
        }
        printf("]");
    }
}
void pop(struct Stack *arr){
    if(isEmpty(*arr)){
        //case1:the stack is empty.
        printf("The stack is empty.\n");
    }else{
        //case2:the stack is not empty.
        int d=arr->stack[arr->lastIndex];
        arr->lastIndex--;
        printf("\nThe popped element is %d",d);
    }
}

//mergin of stack

int merge(struct Stack a, struct Stack b, struct Stack *c){
    

    if(a.lastIndex==-1 && b.lastIndex==-1){
        printf("\nboth the input arrays are empty\n");
        return 0;
    }
    int i=0,j=0,k=0;
    while(i<=a.lastIndex && j<=b.lastIndex){
        if(a.stack[i]<b.stack[j]){
            c->stack[k]=a.stack[i];
            i++;
        }else{
            c->stack[k]=b.stack[j];
            j++;

        }
        k++;
    }
    while(i<=a.lastIndex){
        c->stack[k]=a.stack[i];
        i++;
        k++;
    }
    while(j<=b.lastIndex){
        c->stack[k]=b.stack[j];
        j++;
        k++;
    }

    c->lastIndex=k-1;
    c->capacity=MAX;

    return 1;

}








