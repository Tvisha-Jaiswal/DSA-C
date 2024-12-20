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
void inorder(struct node*root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
int main(){
    struct node * p = createNode(4);
    struct node * p1 = createNode(1);
    struct node * p2 = createNode(6);
    struct node * p3 = createNode(5);
    struct node * p4 = createNode(2);
    
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    inorder(p);
    return 0;
}