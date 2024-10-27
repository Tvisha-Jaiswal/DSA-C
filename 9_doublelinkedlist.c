
#include <stdio.h>
#include <stdlib.h>
struct node{
    int data; 
    struct node*prev;
    struct node*next;
};

void doublelinkedListTraversal(struct node*ptr){
    int i = 1;
        printf("Forward traversal:\n");
    while(ptr != NULL){
        printf("Element %d: %d\n",i, ptr -> data);
        if(ptr -> next == NULL){
            break;
        }
        ptr = ptr -> next;
        i++;
    }
    
        printf("Reverse traversal:\n");
    while(ptr != NULL){
        printf("Element %d: %d\n",i, ptr -> data);
        ptr = ptr -> prev;
        i--;
    }
}
    
int main() {
    struct node*head;
    struct node*second;
    struct node*third;
    struct node*fourth;
    // Allocate memory for nodes in the linked list in Heap
    head = (struct node*)malloc(sizeof(struct node));
    second = (struct node*)malloc(sizeof(struct node));
    third = (struct node*)malloc(sizeof(struct node));
    fourth = (struct node*)malloc(sizeof(struct node));
    
    // Link first and second nodes
    head -> data = 7;
    head -> prev = NULL;
    head -> next = second;
    
    // Link second and third nodes
    second -> data = 11;
    second -> prev = head;
    second -> next = third;
    // Link third and fourth nodes
    third -> data = 41;
    third -> prev = second;
    third -> next = fourth;
    // Link fourth and first nodes
    fourth -> data = 66;
    fourth -> prev = third;
    fourth -> next = NULL;
    
    doublelinkedListTraversal(head);
    
    return 0;
}