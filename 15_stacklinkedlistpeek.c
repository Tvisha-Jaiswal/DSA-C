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
int peek(int pos){
    struct node * ptr = top;
    for(int i = 0; (i < pos-1 && ptr != NULL); i++){
        ptr = ptr-> next;
    }
    if(ptr != NULL){
        return ptr -> data;
    }
    else{
        return -1;
    }
}
int main() {
    top = push(top,28);
    top = push(top,18);
    top = push(top,15);
    top = push(top,7);
    linkedListTraversal(top);
    printf("Value at position 1 is: %d\n", peek(1));
    for(int i = 1; i <= 4; i++){
        printf("The value at position %d is: %d\n", i , peek(i));
    }
    return 0;
}
