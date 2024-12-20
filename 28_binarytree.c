#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*left;
    struct node*right;
};

struct node* createNode(int data){
    struct node*n = (struct node*)malloc(sizeof(struct node));//creating a node pointer
    n->data = data;
    n -> left = NULL;
    n -> right = NULL;
    return n;
}
int main(){
    /*
    // constructing root node
    struct node*p = (struct node*)malloc(sizeof(struct node));
    p->data = 2;
    p->left = NULL;
    p->right = NULL;

    // constructing first node
    struct node*p1 = (struct node*)malloc(sizeof(struct node));
    p1->data = 1;
    p1->left = NULL;
    p1->right = NULL;

    // constructing second node
    struct node*p2 = (struct node*)malloc(sizeof(struct node));
    p2 -> data = 2;
    p2->left = NULL;
    p2->right = NULL;

    // Linking root node with left and right children
    p->left = p1;
    p->right = p2;
    */
    struct node * p = createNode(2);
    struct node * p1 = createNode(1);
    struct node * p2 = createNode(4);
    
    p->left = p1;
    p->right = p2;

    return 0;
}