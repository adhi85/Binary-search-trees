// Inserting an element into BINARY EARCH TREE

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
void inOrder(struct node* root)
{
    if(root!=NULL)
    {
        inOrder(root->left);
        printf("%d ",root->data);
        inOrder(root->right);
    }
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

int insert(node* root, int key)
{
    node* prev = NULL;
    while(root!=NULL){
        prev = root;
        if(root->data == key){
            printf("Same data cannot insert");
            return 0;
        }
        else if(key<root->data)
            root = root->left;
        else
            root = root->right;
    }
    node *new = (struct node*)malloc(sizeof(struct node));
    new = createNode(key);
    if(key<prev->data)
        prev->left =new;
    else
        prev->right = new;
        return 1;
}

int main()
{
    struct node *p,*p1,*p2,*p3,*p4;
    p = createNode(5);
    p1 = createNode(3);
    p2 = createNode(6);
    p3= createNode(1);
    p4 = createNode(4);
    
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    
    int x;
    scanf("%d", &x);
    inOrder(p);
    printf("\nafter\n");
    int y =insert(p,x);
    if(y==1)
        inOrder(p);
        
    return 0;
}



