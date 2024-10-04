#include<stdio.h>
#include<stdlib.h>

//in the circular linked list the last node is connected to the first nodeof the linked list

//structure for Circular linked lists
struct Node{
    int data;//this is the data stored in the linked list.
    struct Node * link;//this is the link of the next node in the ClL.
    int degree;
    int coeff;
};
// making a create Node function

struct Node * createNode(){
    struct Node * ptr;
    ptr=(struct Node *)malloc(sizeof(struct Node));//allocating memory through malloc funnction in heap.
    if(ptr==NULL){
        //case1:Allocation fo the node fails .
        printf("Allocation failed.\n");
        
    }
    return ptr;
}

//making a insert at end function

struct Node * insertAtEnd(struct Node * ptr,int elem){
    struct Node *  newNode=createNode();
    if(newNode==NULL){
        //case1: create Node returns NULL.
        printf("Allocation of the new node failed.");
    }else{
        //case2:Allocation is successffull
        
        //we are not checking if the linekd list is empty or not as even if it is empty in this condition 
        //we will have to add the element in the list .
        
        newNode->data=elem;
        struct Node * temp=ptr;
        while(temp->link!=ptr){
            temp=temp->link;
            
        }
        newNode->link=temp->link;
        temp->link=newNode;
    }
    return ptr;
}

// creating insert At front function().
struct Node * insertAtFront(struct Node * ptr,int elem){
    struct Node * newNode=createNode();
    if(newNode==NULL){
        printf("Allocation Failed\n");
    }else{
        
            // printf("Empty LinkedList.\n");
            
        
            struct Node * temp=ptr;
            while(temp->link!=ptr){
                temp=temp->link;
            }
            temp->link=newNode;
            newNode->link=ptr;
            newNode->data=elem;
            newNode=ptr;
       
    }
    return ptr;
}
//making a display function()

void display(struct Node * ptr){
    
    if(ptr==NULL){//case1: the linked list is empty.
        printf("Empty Linked List\n");
        
    }else{//case 2: the linked list is not empty.
        struct Node * temp=ptr;
        printf("[");
        do{
            
            printf("->%d",temp->data);
            temp=temp->link;
        }while(temp!=ptr);
        printf("]");
    }
}

//making a function to add two polynomials
struct Node * addP(struct Node * ptr1,struct Node * ptr2,struct Node * ptr3){
    //case1: one of the linked list is completely empty.
    if(ptr1==NULL){
        return ptr2;//if first linked list is null we will return directly the second linked list.
    }else if (ptr2==NULL){
        return ptr1;//if second linked list is null we will return directly the first linked list.
    }else{
        //case 2 both the linked list are not null
        struct Node * temp1=ptr1;
        struct Node * temp2=ptr2;
        struct Node * temp3=ptr3;
        while(temp1 !=NULL && temp2 !=NULL){
            if(temp1->degree==temp2->degree){
                temp3->coeff=temp1->coeff+temp2->coeff;
                temp1=temp1->link;
                temp2=temp2->link;
                temp3=temp3->link;
            }else if(temp1->degree>temp2->degree){
                temp3->coeff=temp1->coeff;
                temp1=temp1->link;
                temp3=temp3->link;
            }else if(temp2->degree>temp1->degree){
                temp3->coeff=temp2->coeff;
                temp2=temp2->link;
                temp3=temp3->link;
            }
        }
        //case 3 : when either One of them becomes NULL after traversing.
        while(temp1!=NULL){
             temp3->coeff=temp1->coeff;
                temp1=temp1->link;
                temp3=temp3->link;
        }
        while(temp2!=NULL){
            temp3->coeff=temp2->coeff;
                temp2=temp2->link;
                temp3=temp3->link;
        }
    }
}







