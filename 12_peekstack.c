#include <stdio.h>
#include <stdlib.h>
struct stack{
    int size;
    int top;
    int * arr;
};

int isEmpty(struct stack * ptr){
    if( ptr -> top == -1){
        return 1; //matlab true
    }
    else{
        return 0; //matlab false
    }
}
int isFull(struct stack * ptr){
    if( ptr -> top == ptr-> size -1){
        return 1; //matlab true
    }
    else{
        return 0; //matlab false
    }
}
void push(struct stack * ptr, int val){
    if(isFull(ptr)){
        printf("Stack overflow!,cannot push %d to the stack\n", val);
    }
    else{
        ptr -> top++;
        ptr->arr[ptr->top] = val;
    }
}
int pop(struct stack * ptr){
    if(isEmpty(ptr)){
        printf("Stack underflow!,cannot pop from the stack\n");
        return -1;
    }
    else{
        int val = ptr -> arr[ptr->top];
        ptr -> top--;
        return val;
    }
}
int peek(struct stack*s,int i){
    int arrInd = s->top - i + 1;
    if(arrInd < 0){
        printf("Not a valid position for the stack\n");
        return -1;
    }
    else{
        return s -> arr[arrInd];
    }
}

int main() {
    struct stack * s =(struct stack*)malloc(sizeof(struct stack));
    s->size = 10;
    s->top = -1;
    s->arr = (int*) malloc (s->size*sizeof(int));
    printf("Stack has been created successfully\n");
    printf("Before pushing, Empty %d\n", isEmpty(s));
    printf("Before pushing, Full %d\n", isFull(s));
    push(s,9);
    push(s,11);
    push(s,56);
    push(s,53);
    push(s,32);
    push(s,47);
    push(s,99);
    push(s,10);
    push(s,6);
    push(s,5);
    printf("After pushing, Empty %d\n", isEmpty(s));
    printf("After pushing, Full %d\n", isFull(s));
    
    printf("Popped %d from the arr\n", pop(s));
    for(int j = 1; j <= s->top + 1; j++){
        printf("The value at position %d is %d\n", j , peek(s,j));
    }

    return 0;
}