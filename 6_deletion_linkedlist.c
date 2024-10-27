
#include <stdio.h>
#include <stdlib.h>
struct node{
    int data; 
    struct node*next;
};
void linkedListTraversal(struct node*ptr){
    int i = 1;
    while(ptr != NULL){
        printf("Element %d: %d\n",i, ptr -> data);
        ptr = ptr -> next;
        i++;
    }
}
struct node * deleteFirst(struct node * head){
    struct node*ptr = head;
    head = head -> next;
    free(ptr);
    return head;
}
struct node * deleteAtIndex(struct node * head, int index){
    struct node*p = head;
    struct node*q = head->next;
    for(int i = 1; i < index -1; i++){
        p = p -> next;
        q = q -> next;
    }
    p -> next = q -> next;
    free(q);
    return head;
}
struct node * deleteLast(struct node * head){
    struct node*p = head;
    struct node*q = head->next;
    while(q -> next != NULL){
        p = p->next;
        q = q->next;
    }
    p -> next = NULL;
    free(q);
    return head;
}
struct node * deleteAtValue(struct node * head, int value){
    struct node*p = head;
    struct node*q = head->next;
    while(q -> data != value && q-> next != NULL){
        p = p -> next;
        q = q -> next;
    }
    if(q->data == value){
        p-> next = q->next;
        free(q);
    }
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
    head -> data = 4;
    head -> next = second;
    
    // Link second and third nodes
    second -> data = 3;
    second -> next = third;
    // Link third and fourth nodes
    third -> data = 8;
    third -> next = fourth;
    // Terminate the list at last node
    fourth -> data = 1;
    fourth -> next = NULL;
    printf("Linked list before deletion:\n");
    linkedListTraversal(head);
    // head = deleteFirst(head);
    // head = deleteAtIndex(head,2);
    // head = deleteLast(head);
    head = deleteAtValue(head,8);
    printf("Linked list after deletion:\n");
    linkedListTraversal(head);
    return 0;
}