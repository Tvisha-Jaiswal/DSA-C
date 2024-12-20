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
void insert(struct node*root,int key){
    struct node*prev = NULL;
    while(root!=NULL){
        prev = root;
        if(key == root -> data){
            printf("\nCannot insert,%d already in BST tree",key);
            return;
        }
        else if(key<root->data){
            root = root -> left;
        }
        else{
            root = root->right;
        }
    }
    struct node*new = createNode(key);
    if(key<prev->data){
        prev->left = new;
    }
    else{
        prev->right = new;
    }
}
void inorder(struct node*root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
int main(){
    struct node * p = createNode(5);
    struct node * p1 = createNode(3);
    struct node * p2 = createNode(6);
    struct node * p3 = createNode(1);
    struct node * p4 = createNode(4);
    
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    inorder(p);
    insert(p,6);
    printf("\n");
    inorder(p);
    return 0;
}