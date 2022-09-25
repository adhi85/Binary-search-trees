// CHECKING IF A BINARY TREE IS A BINARY SEARCH TREE

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

int isBST(struct node* root)
{
    if(root!=NULL)
    {
        static struct node* prev = NULL;
        if(!isBST(root->left))
            return 0;
        if(prev!= NULL && prev->data>=root->data)
            return 0;
        
        prev =root;
        return isBST(root->right);
    }
    else{
        return 1;
    }
}

int main()
{
    struct node *p,*p1,*p2,*p3,*p4;
    p = createNode(5);
    p1 = createNode(3);
    p2 = createNode(6);
    p3= createNode(10);
    p4 = createNode(4);
    
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    
    
    int x = isBST(p);
    if(x==1){
        printf("Yes");
    }
    else
        printf("No");
    
    return 0;
}

// CREDITS: https://github.com/adhi85
