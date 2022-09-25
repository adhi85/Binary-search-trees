// Searching for an element in a BINARY SEARCH TREE

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

node* search(node * root, int key)
{
    if(root==NULL)
        return NULL;
    if(root->data == key)
        return root;
    else if(key<root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

node * searchIter(node* root, int key)
{
   while(root!=NULL){
    if(key == root->data)
        return root;
    else if(key<root->data)
        root = root->left;
    else
        root=root->right;
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
    
    int x;
    scanf("%d", &x);
    
    node* finded = searchIter(p, x);
    
    printf("Yes %d exists", finded->data);
    return 0;
}



