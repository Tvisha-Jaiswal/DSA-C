
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
struct node * insertAtFirst(struct node * head, int data){
    struct node * ptr = (struct node *)malloc(sizeof(struct node));
    ptr -> next = head;
    ptr -> data = data;
    return ptr;
}

struct node * insertAtIndex(struct node * head, int data, int index){
    struct node * ptr = (struct node *)malloc(sizeof(struct node));
    struct node * p = head;
    int i = 0;
    while(i != index-1){
        p = p->next;
        i++;
    }
    ptr -> data = data;
    ptr -> next = p -> next;
    p -> next = ptr;
    return head;
}

struct node * insertAtEnd(struct node * head, int data){
    struct node * ptr = (struct node *)malloc(sizeof(struct node));
    ptr -> data = data;
    struct node * p = head;
    while(p->next != NULL){
        p = p -> next;
    }
    p -> next = ptr;
    ptr -> next = NULL;
    return head;
}

struct node* insertAfterNode(struct node* head,struct node* prevnode, int data){
    struct node * ptr = (struct node *)malloc(sizeof(struct node));
    ptr -> data = data;
    ptr->next = prevnode -> next;
    prevnode -> next = ptr;
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
    // Terminate the list at last node
    fourth -> data = 66;
    fourth -> next = NULL;
    
    linkedListTraversal(head);
    // head = insertAtFirst(head,56);
    // head = insertAtIndex(head,56,1);
    // head = insertAtEnd(head,56);
    head = insertAfterNode(head,third,45);
    linkedListTraversal(head);
    return 0;
}