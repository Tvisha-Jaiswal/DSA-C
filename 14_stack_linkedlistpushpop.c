#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node*next;
};

struct node*top = NULL;

void linkedListTraversal(struct node*ptr){
    int i = 1;
    while(ptr != NULL){
        printf("Element %d: %d\n",i, ptr -> data);
        ptr = ptr -> next;
        i++;
    }
}  
int isEmpty(struct node*top){
    if(top==NULL){
        return 1;
    }
    else{
        return 0;
    }
}
int isFull(struct node*top){
    struct node * p = (struct node*)malloc(sizeof(struct node));
    if(p == NULL){
        return 1;
    }
    else{
        return 0;
    }
}
int pop(struct node*tp){
    if(isEmpty(tp)){
        printf("Stack underflow\n");
    }
    else{
        struct node * n = tp;
        top = tp -> next;
        int x = n -> data;
        free(n);
        return(x);
    }
}
struct node*push(struct node*top, int x){
    if(isFull(top)){
        printf("Stack overflow\n");
    }
    else{
        struct node * n = (struct node *)malloc(sizeof(struct node));
        n -> data = x;
        n -> next = top;
        top = n;
        return top;
    }
}
int main() {
    top = push(top,78);
    top = push(top,7);
    top = push(top,8);
    linkedListTraversal(top);
    int element = pop(top);
    printf("Popped element is %d\n", element);
    linkedListTraversal(top);
    return 0;
}
