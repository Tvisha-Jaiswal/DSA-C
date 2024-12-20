#include <stdio.h>
#include <stdlib.h>
struct stack{
    int size;
    int top;
    char * arr;
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
void push(struct stack * ptr, char val){
    if(isFull(ptr)){
        printf("Stack overflow!,cannot push %d to the stack\n", val);
    }
    else{
        ptr -> top++;
        ptr->arr[ptr->top] = val;
    }
}
char pop(struct stack * ptr){
    if(isEmpty(ptr)){
        printf("Stack underflow!,cannot pop from the stack\n");
        return -1;
    }
    else{
        char val = ptr -> arr[ptr->top];
        ptr -> top--;
        return val;
    }
}
int parenthesisMatch(char * exp){
    // create and initialize the stack
    struct stack * sp = (struct stack*)malloc(sizeof(struct stack));
    sp -> size = 100;
    sp -> top = -1;
    sp -> arr = (char*)malloc(sp->size*sizeof(char));
    
    for(int i = 0; exp[i]!='\0'; i++){
        if(exp[i] == '('){
            push(sp,'(');
        }
        else if(exp[i] == ')'){
            if(isEmpty(sp)){
                return 0;
            }
            else{
                pop(sp);
            }
        }
    }
    if(isEmpty(sp)){
        return 1;
    }
    else{
        return 0;
    }
}
int main() {
    char * exp = "8*(9)";
    if (parenthesisMatch(exp)){
        printf("The parenthesis is matching\n");
    }
    else{
        printf("The parenthesis is not matching\n");
    }
    return 0;
}