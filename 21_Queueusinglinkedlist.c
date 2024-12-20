#include <stdio.h>
#include <stdlib.h>

struct node *f = NULL;
struct node *r = NULL;

struct node
{
    int data;
    struct node *next;
};
void linkedListTraversal(struct node*ptr){
    int i = 1;
    while(ptr != NULL){
        printf("Element %d: %d\n",i, ptr -> data);
        ptr = ptr -> next;
        i++;
    }
}
void enqueue(int val)
{
    struct node*n = (struct node*)malloc(sizeof(struct node));
    if(n == NULL){
        printf("Queue is full");
    }
    else{
        n -> data = val;
        n -> next = NULL;
        if(f == NULL){
            f = r = n;
        }
        else{
            r -> next = n;
            r = n;
        }
    }
}
int dequeue(){
    int val = -1;
    // struct node*ptr = f;
    if(f == NULL){
        printf("Queue is empty\n");
    }
    else{
        val = f->data;
        f = f -> next;
        // val = ptr ->data;
        // free(ptr);
    }
    return val;
}
int main()
{
    linkedListTraversal(f);
    enqueue(35);
    enqueue(45);
    enqueue(55);
    enqueue(65);
    linkedListTraversal(f);
    printf("Dequeing element is %d\n",dequeue());
    printf("Dequeing element is %d\n",dequeue());
    printf("Dequeing element is %d\n",dequeue());
    linkedListTraversal(f);
    return 0;
}