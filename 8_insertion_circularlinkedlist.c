
#include <stdio.h>
#include <stdlib.h>
struct node{
    int data; 
    struct node*next;
};
void circularlinkedListTraversal(struct node*head){
    struct node*ptr = head;
    // printf("Element %d: %d\n",1, ptr -> data);
    //     ptr = ptr -> next;
    // int i = 2;
    // while(ptr != head){
    //     printf("Element %d: %d\n",i, ptr -> data);
    //     ptr = ptr -> next;
    //     i++;
    // }
    int i = 1;
    do{
        printf("Element %d: %d\n",i, ptr -> data);
        ptr = ptr -> next;
        i++;
    } while(ptr != head);
}

struct node* insertAtFirst(struct node*head, int data){
    struct node * ptr = (struct node *)malloc(sizeof(struct node));
    ptr -> data = data;
    struct node * p = head -> next;
    while(p -> next != head){
        p = p->next;
    }
    // At this point p points to last node of circular linked list
    p -> next = ptr;
    ptr -> next = head;
    head = ptr;
    
    return head;
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
    head -> next = second;
    
    // Link second and third nodes
    second -> data = 11;
    second -> next = third;
    // Link third and fourth nodes
    third -> data = 41;
    third -> next = fourth;
    // Link fourth and first nodes
    fourth -> data = 66;
    fourth -> next = head;
    
    circularlinkedListTraversal(head);
    head = insertAtFirst(head,80);
    circularlinkedListTraversal(head);
    
    return 0;
}