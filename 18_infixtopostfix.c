#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct stack{
    int size;
    int top;
    char * arr;
};

int isFull(struct stack * ptr){
    if(ptr->top == ptr->size-1){
        return 1;
    }
    else{
        return 0;
    }
}
int isEmpty(struct stack * ptr){
    if( ptr -> top == -1){
        return 1; //matlab true
    }
    else{
        return 0; //matlab false
    }
}
void push(struct stack * ptr, char x){
    if(!isFull(ptr)){
        ptr -> top++;
        ptr->arr[ptr->top] = x;
    }
}

char pop(struct stack * ptr){
    if(!isEmpty(ptr)){
        int a = ptr->arr[ptr->top];
        ptr->top--;
        return a;
    }
    else{
        return '\0';
    }
}
int stackTop(struct stack * s){
    return s->arr[s->top];
}
int isoperator(char a){
    if(a == '*' || a == '/' || a == '+' || a == '-'){
        return 1;
    }
    else{
        return 0;
    }
}
int prec(char ch){
    if(ch == '*' || ch == '/'){
        return 3;
    }
    else if(ch == '+' || ch == '-'){
        return 2;
    }
    else{
        return 0;
    }
}
char*intopo(char * infix){
    struct stack * sp = (struct stack *)malloc(sizeof(struct stack));
    sp -> size = 10;
    sp -> top = -1;
    sp -> arr = (char *)malloc((sp->size)*sizeof(char));
    char * pos = (char*)malloc((strlen(infix)+1)*sizeof(char));
    int i = 0, j = 0;
    while(infix[i] != '\0'){
        if(!isoperator(infix[i])){
            pos[j] = infix[i];
            i++,j++;
        }
        else{
            if(prec(infix[i])>prec(stackTop(sp))){
                push(sp,infix[i]);
                i++;
            }
            else{
                pos[j] = pop(sp);
                j++;
            }
        }
    }
    while(!isEmpty(sp)){
        pos[j] = pop(sp);
        j++;
    }
    pos[j] = '\0';
    return pos;
}
int main(){
    char * infix = "a-b+t/6";
    printf("postfix is %s",intopo(infix));
    return 0;
}