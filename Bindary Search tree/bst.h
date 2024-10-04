#include<stdio.h>
#include<stdlib.h>
//structure of a binary search tree

struct Node {
    int data;
    struct Node * l_child;
    struct Node * r_child;
};

//create Node function

struct Node * createNode(int key){
    struct Node * p=NULL;
    p=(struct Node *)malloc(sizeof(struct Node));
    p->data=key;
    p->l_child=p->r_child=NULL;
return p;
}


// insert in a bst
// iterative approach.
struct Node* insert(struct Node* root, int data){
	struct Node* newNode=NULL;
	if(root==NULL){
		newNode=createNode(data);
		return newNode;
	}
	if(root->data<data){
		root->r_child =insert(root->r_child,data);
	}
	else if(root->data>data){	
		root->l_child= insert(root->l_child,data);
	}
	else{
		printf("Duplicate found. Can't insert\n");
		return root;
	}
	return root;
}
//recursive function search in tree

struct Node * searchBST(struct Node * root,int key){
    if(root==NULL){
        return NULL;
    }
    else if(key==root->data){
        return root;
    }else if(key<root->data){
        return searchBST(root->l_child,key);
    }else{
        return searchBST(root->r_child,key);
    }

}
void inorder(struct Node * root){
    if(root!=NULL){
        inorder(root->l_child);
        printf(" %d",root->data);
        inorder(root->r_child);
    }
}
void preorder(struct Node * root){
    if(root!=NULL){
        printf(" %d",root->data);
        preorder(root->l_child);
        preorder(root->r_child);
    }
}

void postorder(struct Node * root){
    if(root!=NULL){
    postorder(root->l_child);
    postorder(root->r_child);
    printf(" %d",root->data);
    }
}
int totalNodes(struct Node* root){
	if(root!=NULL){
		return totalNodes(root->l_child)+totalNodes(root->r_child)+1;
	}
    else{
        return 0;
    }
}

int leafNodes(struct Node* root){
	if(root==NULL){
		return 0;
	}
	if(root->l_child==NULL && root->r_child==NULL){
		return 1;
	}
	else{
		return leafNodes(root->l_child)+leafNodes(root->r_child);
	}
}

int nonLeafNode(struct Node* root){
	if(root==NULL || (root->l_child==NULL && root->r_child==NULL)){
		return 0;
	}
	else{
		return nonLeafNode(root->l_child)+nonLeafNode(root->r_child)+1;
	}
}
int height(struct Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        int left = height(root->l_child);
        int right = height(root->r_child);

        return (left > right) ? left + 1 : right + 1;
    }
}

int internalNodes(struct Node *root){
    return nonLeafNode(root)-1;

}

//delete function

struct Node * delete(struct Node * root,int key){
    if(root==NULL){
        printf("\nThe Tree is already empty\n");
    }

    if(key<root->data){
        root->l_child=delete(root->l_child,key);
    }else if(key>root->data){
        root->r_child=delete(root->r_child,key);
    }else{
        if(root->l_child==NULL){
            struct Node * temp=root->r_child;
            free(root);
            return temp;
        }else if(root->r_child==NULL){
            struct Node * temp=root->l_child;
            free(root);
            return temp; 
        }
    }
}


//search in a binary search tree
int * Search(struct Node * root,int key){
    while(root!=NULL){
        if(root->data==key){
            return key;//if found return here.
        }else if(root->data<key){
            root=root->l_child;
        }else{
            root=root->r_child;
        }
    }

    return -1;// if nothing is found.
}
//