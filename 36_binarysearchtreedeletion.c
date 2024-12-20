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
struct node*inOrderPredecessor(struct node * root){
    root = root ->left;
    while (root->right != NULL)
    {
        root = root -> right;
    }
    return root;
    
}
struct node*deleteNode(struct node*root,int value){
    struct node* iPre;
    if(root == NULL){
        return NULL;
    }
    if(root->left == NULL && root->right == NULL){
        free(root);
        return NULL;
    }
    if(value<root->data){
        root->left = deleteNode(root->left,value);
    }
    else if(value>root->data){
        root->right = deleteNode(root->right,value);
    }
    // deletion strategy
    else{
        iPre = inOrderPredecessor(root);
        root -> data = iPre ->data;
        root->left = deleteNode(root->left,iPre->data);
    }
    return root;
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
    printf("\n");
    deleteNode(p,3);
    inorder(p);
    printf("\n");
    deleteNode(p,5);
    inorder(p);
    return 0;
}