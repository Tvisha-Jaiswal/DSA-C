
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

struct node *deletion1(struct node *head, int index)
{
    int a = index;
    if (head == NULL)
    {
        printf("The list is empty");
        return NULL;
    }
    else if (index < 0)
    {
        printf("Invalid index,deletion unsuccessful\n");
        return head;
    }
    else if (head->next == head)
    {
        printf("The removed node value is %d", head->data);
        free(head);
        return NULL;
    }
    else
    {
        struct node *ptr = head;
        struct node *p = head->next;
        // printf("ptr : %d, p : %d\n",ptr->data,p->data);
        while (index > 0 || p->next != ptr)
        {
            if (index != 0)
            {  
                ptr = ptr->next;
                if (ptr == head)
                {
                    printf("Index out of bond, deletion unsuccessful\n");
                    return head;
                }
                // printf("ptr %d \n",ptr->data);
                index--;
            }
            p = p->next;
            printf("p %d \n", p->data);
        }
        printf("The removed element is %d\n", ptr->data);
        if (a == 0)
        {
            head = head->next;
            p->next = head;
            free(ptr);
            return head;
        }
        else
        {
            p->next = ptr->next;
            free(ptr);
            // printf("%d",head->data);
            return head;
        }
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
    head = deletion1(head, 3);
    circularlinkedListTraversal(head);
    // head = deletion1(head,5);
    // circularlinkedListTraversal(head);

    return 0;
}