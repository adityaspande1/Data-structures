#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;//this is the data which the node stores.
    struct Node * link;//this is the link to the next node;
};
//making a create node function

struct Node * createNode(){
    struct Node * ptr;
    ptr=(struct Node *)malloc(sizeof(struct Node));//allocating a pointer in the heap memory.
    if(ptr==NULL){//if no allocation is made.
        printf("Allocation Failed\n");
    }
    
    return ptr;
    
}
//making a function insert at end;

struct Node * insertAtEnd(struct Node * ptr,int elem){
    //first creating a new node for allocation.
    struct Node * newNode=createNode();
    if(newNode==NULL){
        // if newNode is Null then the allocation is failed.
        printf("Allocation is failed\n");
    }
    else{
        // case 2: Allocation successful. 
        newNode->data=elem;
        newNode->link=NULL;//As it is the last node Now so it should point to NULL.
        if(ptr==NULL){//case2.1 : sll is empty
            ptr=newNode;//assigning the ptr with neNode address.
        }else{
            struct Node * temp=ptr;//new pointer made so that is can be used to traverse in the SLL.
            while(temp->link!=NULL){
                temp=temp->link;
            }
            temp->link=newNode;//assigning the value of address of neNode to temp's link as 
            //temp is now second last node.
        }
    }
    return ptr;
}
//making a length function
int length(struct Node * ptr){
    int length1=0;//making a counter.
    struct Node * temp=ptr;// we use a temp pointer as we do not want to \not
    //loose the address of the head pointer which is stored in ptr.
    while(temp!=NULL){
        temp=temp->link;
        length1++;
    }
    
    return length1;
}
//making a display function for printing the conttent of linked list.
void display(struct Node * ptr){
    printf("[");
    struct Node * temp= ptr;
    while(temp!=NULL){
        
        printf("->%d",temp->data);
        printf("[");
        printf("%lu",temp);
        printf("]");
       temp=temp->link;
    }
     printf("]");
}
// making an insert at start function for SLL.

struct Node * insertAtStart(struct Node * ptr,int elem){
    //creating the node to insert.
    struct Node * newNode=createNode();
    if(newNode==NULL){
        printf("THe allocation of the new Node failed\n");
    }
    else{
        newNode->data=elem;
        newNode->link=ptr;
        if(ptr==NULL){//case : the sll is currently empty.
            ptr=newNode;
            
        }else{
            newNode->link=ptr;
            ptr=newNode;
        }
    }
    return ptr;
}
//delete front function

struct Node * deleteFront(struct Node * ptr){
    struct Node * temp=ptr;
    if(ptr==NULL){//case 1 : the  linked list is empty.
        printf("THe linked List is already empty.\n");
    }else{
        temp=ptr;//storing the ptr node in temp;
        int d= ptr->data;// storing the data in ptr to a variable
        ptr=ptr->link;//changing the ptr address to the address of the second element
        // which the ptr currently contained in the link part of itself.
        free(temp);
        //now freeing the space which the ptr originally contained .
    }
    return ptr;
}

//making a delete at end function.

struct Node * deleteAtEnd(struct Node * ptr){
    //making a temperory node to store the ptr;
    struct Node * temp=ptr;
    if(ptr==NULL){//case 1 : linked list is empty.
        printf("THe linked list is already empty.\n");
    }else{
        //checking temp->link->link so that the code checks the the address stored in 
        //the node pointing to the link of another next node.
        while(temp->link->link!=NULL){
            temp=temp->link;
        }
        int d=temp->link->data;
        free(temp->link);
        temp->link=NULL;
    }
    return ptr;
}
//creating a function for inserting at a specified allocation
struct Node * insertAtSpecified(struct Node * ptr,int pos,int elem){
    //we take position as a parameter in this to enter at a specified location.
    
    
    //case1: The SLl is empty.
    
    if(ptr==NULL){
        printf("E,pty Linked list.\n");
        
    }
    else{
        //case2:the sll is not empty.
        //creating a new node;
        //making a length counter.
        struct Node * newNode=createNode();
        struct Node * temp=ptr;//making a temperory pointer for traversing.
        int count=1;
        
       //case 3 : if the allocation failed of the new node;
       if(newNode==NULL){
           printf("Allocation Faild.");
       }
       //case4: if the pos specified is invalid.
       else if(pos<1 || pos>length(ptr)){
           printf("Invalid Position\n");
       }
       else{
           while(count<pos-1){
               temp=temp->link;
               count++;
           }
           newNode->link=temp->link;
           temp->link=newNode;
           newNode->data=elem;
           
       }
        
    }
    
    return ptr;
    
}

//now delete element at a specified location.

struct Node * deleteAtSpecified(struct Node * ptr,int pos){
    //case 1: the linked list given is empty.
    if(ptr==NULL){
        printf("Empty Linked List\n");
        
    }else if(pos<1 || pos>length(ptr)){
        printf("Invalid Position\n");
    }else if(pos==1){
       ptr=deleteFront(ptr);
    }
    else{
        //making a temperory pointer
        struct Node * temp= ptr;
        int count=0;
        while(count<pos-1){
            temp=temp->link;
            count++;
        }
        //first we will store the data which we will be delteing
        int d= temp->link->data;
        printf("THe deleted Element is %d\n",d);
        temp->link=temp->link->link;
    }
    return ptr;
}

// search algorithm

int searchSLL(struct Node * ptr,int key){
    //case1: chaeck if the linked list is Empty
    if(ptr==NULL){
        printf("THe linked list is empty.\n");
    }else{//case2:the linked list is not empty
    
        int count=0;
        struct Node * temp=ptr;
        while(temp->link!=NULL){
            count++;
            if(temp->data==key){
                return count;
            }
            temp=temp->link;
        }
    }
    return -1;//if the element is not found int the linked list.
}
//reversing aa sll
struct Node * reverse(struct Node * ptr){
    if(ptr==NULL){
        printf("The SLL is empty\n");
        
    }
    
    struct Node * p1=NULL;//previous pointer
    struct Node * p2=ptr;//current pointer
    struct Node * p3=NULL;//next pointer
    
    while(p2!=NULL){
        p3=p2->link;
        p2->link=p1;
        p1=p2;
        p2=p3;
        
    }
    ptr=p1;
    return ptr;
}

//sorting of array
//making a swap function for sorting 
struct Node * sllSort(struct Node * ptr){
        if(ptr==NULL){
            printf("linked list is empty\n");
        }
   
    for(int i=0;i<length(ptr);i++){
     struct Node * temp=ptr;
        for(int j=0;j<length(ptr)-i-1;j++){
           if(temp->data > temp->link->data){
            int d= temp->link->data;//it starts swaping here
            temp->link->data=temp->data;
            temp->data=d;
           } 
          temp=temp->link;
        }
        temp=ptr;
        
         
    }
    
    
    return ptr;
    }
//copy algotihym
struct Node* copy(struct Node * ptr){
    struct Node * ptr1=NULL;
    struct Node * temp=ptr;
    while(temp!=NULL){
        ptr1=insertAtEnd(ptr1,temp->data);
        temp=temp->link;
    }
    return ptr1;
}

//merge sll
struct Node * merge(struct Node * ptr1,struct Node * ptr2,struct Node * ptr3){
        //if(ptr1==NULL && ptr2!=NULL){
        //case1
        //ptr3=copy(ptr2);
        //return ptr3;
        //}else if(ptr1!=NULL && ptr2==NULL){
        //case 2 
        //ptr3=copy(ptr1);
        //return ptr3;
        //}ee
     ptr3=NULL;
    ptr1=sllSort(ptr1);
    ptr2=sllSort(ptr2);
    struct Node * temp1=ptr1;
    struct Node * temp2=ptr2;
    while(temp1!=NULL && temp2!=NULL){
        if(temp1->data>temp2->data){
            ptr3=insertAtEnd(ptr3,temp2->data);
            temp2=temp2->link;
        }else{
            ptr3=insertAtEnd(ptr3,temp1->data);
            temp1=temp1->link;
    }
    
    }
    while(temp1!=NULL){
        ptr3=insertAtEnd(ptr3,temp1->data);
        temp1=temp1->link;
    }
    while(temp2!=NULL){
        ptr3=insertAtEnd(ptr3,temp2->data);
        temp2=temp2->link;
            }
    return ptr3;
}







