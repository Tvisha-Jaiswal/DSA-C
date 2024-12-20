#include <stdio.h>
struct node{
    int key;
    struct node*left;
    struct node*right;
    int height;
};

int getHeight(struct node * n){
    if(n == NULL){
        return 0;
    }
    return n->height;
}

struct node*createNode(int key){
    struct node*node = (struct node*)malloc(sizeof(struct node));
    node->key=key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
}

int getBalanceFactor(struct node*n){
    if(n==NULL){
        return 0;
    }
    return getHeight(n->left)-getHeight(n->right);
}

struct node*leftRotate(struct node*y){
    struct node*x = y->left;
    struct node*T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->left),getHeight(y->right))+1;
    x->height = max(getHeight(x->right),getHeight(x->left))+1;
}
struct node*rightRotate(struct node*x){
    struct node*x = y->left;
    struct node*T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->left),getHeight(y->right))+1;
    x->height = max(getHeight(x->right),getHeight(x->left))+1;

    return y;
}

struct node*insert(struct node*node,int key){
    if(node == NULL){
        return (createNode(key));
    }

    if(key<node->key){
        node->left = insert(node->left,key);
    }
    else if(key> node->key){
        node->right =insert(node->right,key);
        return node;
    }
    int bf = getBalanceFactor(node);
    
}