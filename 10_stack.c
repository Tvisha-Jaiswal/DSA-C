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
int main() {
    struct stack * s;
    s = (struct stack*)malloc(sizeof(struct stack));
    s->size = 80;
    s->top = -1;
    s->arr = (int*) malloc (s->size*sizeof(int));
    // pushing an element manually
    s->arr[0] = 7;
    s->top++;
    // checking if stack is empty
    if(isEmpty(s)){
        printf("The stack is empty");
    }
    else{
        printf("The stack is non-empty");
    }

    return 0;
}