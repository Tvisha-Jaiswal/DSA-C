
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void circularlinkedListTraversal(struct node *head)
{
    struct node *ptr = head;
    int i = 1;
    do
    {
        printf("Element %d: %d\n", i, ptr->data);
        ptr = ptr->next;
        i++;
    } while (ptr != head);
}

struct node *insertAtFirst(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    struct node *p = head->next;
    while (p->next != head)
    {
        p = p->next;
    }
    // At this point p points to last node of circular linked list
    p->next = ptr;
    ptr->next = head;
    head = ptr;

    return head;
}
struct node *deletion(struct node *head, int index)
{
    int a;
    if (head == NULL)
    {
        printf("The linkedlist is empty");
        return NULL;
    }
    struct node *ptr = head;
    struct node *p = head;
    if (index == 0)
    {
        a = head->data;
        printf("The removed note value is %d\n", a);
        while (p->next != head)
        {
            p = p->next;
        }
        head = head->next;
        p->next = head;
        free(ptr);
        return head;
    }
    else if (index > 0)
    {
        ptr = ptr->next;
        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;
            ptr = ptr->next;
            if (ptr == head)
            {
                printf("Index out of bond,deletion unsuccessfull\n");
                return head;
            }
        }
        a = ptr->data;
        printf("The removed note value is %d\n", a);
        p->next = ptr->next;
        free(ptr);
        return head;
    }
    else
    {
        printf("Invalid index");
        return NULL;
    }
}
int main()
{
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *fourth;
    // Allocate memory for nodes in the linked list in Heap
    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));

    // Link first and second nodes
    head->data = 7;
    head->next = second;

    // Link second and third nodes
    second->data = 11;
    second->next = third;
    // Link third and fourth nodes
    third->data = 41;
    third->next = fourth;
    // Link fourth and first nodes
    fourth->data = 66;
    fourth->next = head;

    circularlinkedListTraversal(head);
    head = insertAtFirst(head, 80);
    circularlinkedListTraversal(head);
    head = deletion(head, 0);
    circularlinkedListTraversal(head);
    head = deletion(head, 5);
    circularlinkedListTraversal(head);

    return 0;
}