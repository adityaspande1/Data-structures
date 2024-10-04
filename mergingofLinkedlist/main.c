//date 26/10/23
#include <stdio.h>
#include"sll1.h"

int main()
{
    
    struct Node * head=NULL;
    struct Node * head1=NULL;
    struct Node * head2=NULL;
    head=insertAtStart(head,5);
    head=insertAtStart(head,4);
    head=insertAtStart(head,14);
    head=insertAtStart(head,2);
    head=insertAtStart(head,13);
    head1=insertAtStart(head1,73);
    head1=insertAtStart(head1,26);
    head1=insertAtStart(head1,2);
    head1=insertAtStart(head1,1);
    head1=insertAtStart(head1,17);
    display(head);
    printf("\n");
    head=insertAtSpecified(head,2,0);
    display(head);
    printf("\n");
    head=deleteAtSpecified(head,3);
    display(head);
    int d= searchSLL(head,4);
    printf("\nThe element is present at : %d \n",d);
    head=reverse(head);
    display(head);
    printf("\n");
    printf("The linked list after sorting is\n ");
    head=sllSort(head);
    display(head);
   printf("\n");
   printf("THe linked list after mergin is :\n");
    head2=merge(head,head1,head2);
    display(head2);
    return 0;
    
}


