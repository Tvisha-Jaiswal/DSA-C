#include <stdio.h>
#include <stdlib.h>
struct circularqueue{
    int size;
    int f;
    int r;
    int*arr;
};
int isFull(struct circularqueue*q){
    if(((q->r+1)%q->size)==q->f){
        return 1;
    }
    return 0;
}
void enqueue(struct circularqueue*q, int val){
    if(isFull(q)){
        printf("This queue is full\n");
    }
    else{
        q->r = (q->r +1)%q->size;
        q->arr[q->r] = val;
    }
}
int isEmpty(struct circularqueue*q){
    if(q->r == q->f){
        return 1;
    }
    return 0;
}
int dequeue(struct circularqueue*q){
    int a = -1;
    if(isEmpty(q)){
        printf("This queue is Empty\n");
    }
    else{
        q->f = (q->f + 1)%q->size;
        a = q->arr[q->f];
    }
    return a;
}
int main() {
    struct circularqueue q;
    q.size = 100;
    q.f = q.r = -1;
    q.arr = (int*)malloc(q.size*sizeof(int));
    // enqueue few elements
    enqueue(&q,12);
    enqueue(&q,15);
    printf("Dequeuing element %d\n",dequeue(&q));
    printf("Dequeuing element %d\n",dequeue(&q));
    if(isEmpty(&q)){
    printf("Queue is empty\n");}
    if(isFull(&q)){
    printf("Queue is full\n");}
    
}