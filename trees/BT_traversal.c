// All three types of traversal preorder postorder and inorder 

#include <stdlib.h>
#include <stdio.h>

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}node;

struct node* createNode(int data)
{
    struct node *n = (struct node*)malloc(sizeof(struct node));
    n->data=data;
    n->left=NULL;
    n->right= NULL;
    
    return n;
}

void preOrder(struct node* root)
{
    if(root!=NULL){
        printf("%d ",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(struct node* root)
{
    if(root!=NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
        
    }
}
void inOrder(struct node* root)
{
    if(root!=NULL)
    {
        inOrder(root->left);
        printf("%d ",root->data);
        inOrder(root->right);
    }
}

int main()
{
    struct node *p,*p1,*p2,*p3,*p4;
    p = createNode(4);
    p1 = createNode(1);
    p2 = createNode(6);
    p3= createNode(5);
    p4 = createNode(2);
    
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    
    preOrder(p);
    printf("\n");
    postOrder(p);
    printf("\n");
    inOrder(p);
    return 0;
}

// CREDITS: https://github.com/adhi85