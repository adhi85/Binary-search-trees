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


//function for getting the inorder inorder Predecessor
node *inorderPredecessor(node* root)
{
    root = root->left;
    while(root->right!=NULL)
    {
        root=root->right;
    }
    return root;
}

node* deleteNode(node* root, int value)
{
    node* InorPrede;
    if(root==NULL)
        return NULL;
    //in the case of a deleting a leaf node
    if(root->left ==NULL && root->right==NULL)
    {
        free(root);
        return NULL;
    }
    //searching for the node to delete
    if(value< root->data){
       root->left= deleteNode(root->left, value);
        
    }
    else if(value> root->data){
     root->right =deleteNode(root->right, value);
     
    }
    //deleting the node after searching
    else{
        InorPrede = inorderPredecessor(root);
        root->data= InorPrede->data;
        root->left = deleteNode(root->left, InorPrede->data);
    }
    return root;
    
}

int main()
{
    int size,i=0,value;
    scanf("%d", &size);
    
    int arr[size];
    
    while(i<size){
        scanf("%d", &arr[i]);
        i++;
    }
    
    struct node *p[size];
    
    for(i =0; i<size; i++)
    {
        p[i]=createNode(arr[i]);
    }
    
    
    p[0]->left = p[1];
    p[0]->right = p[2];
    p[1]->left = p[3];
    p[1]->right = p[4];
    p[2]->left = p[5];
    p[3]->left = p[6];
    p[5]->left = p[7];
    p[5]->right = p[8];
    
    char option; 
    scanf(" %c",&option);
    
    while(option!='b'){
    switch(option){
        case 'a':
        scanf("%d", &value);
        deleteNode(p[0],value);
        break;
        
        case 'b':
        printf("Inorder: ");
        inOrder(p[0]);
        break;
        
        default:
        printf("Enter correct option");
        break;
        
    }
    }    
    return 0;
}



