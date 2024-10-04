#include<stdio.h>
#include"bst.h"

int main(){
    // printf("hello");
    struct Node * root=NULL;
    root=insert(root,1);
    root=insert(root,2);
    root=insert(root,3);
    root=insert(root,4);
    inorder(root);
    printf(" This is the preorder\n ");
    preorder(root);
    printf(" This is the postorder\n ");
    postorder(root);
    int d=totalNodes(root);
    printf(" THe total number of nodes %d\n",d);  
    int h=height(root);
    printf("The height of the tree is %d\n",h) ;
    // int i=internalNodes(root);
    // printf("The internal nodes  is %d\n",i) ;
    printf(" The element is found is %d",Search(root,5));


    
    // printf()
}