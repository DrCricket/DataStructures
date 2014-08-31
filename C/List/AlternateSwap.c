#include<stdio.h>
#include<stdlib.h>


typedef struct Node
{
    int val;
    struct Node *next;
}Node;

void push(Node **head,int t)
{
    Node *curr = *head;
    Node *n = (Node *)malloc(sizeof(Node));
    n->val = t;
    n->next = curr;
    (*head) = *(&n);
    return;
}

void print(Node *head)
{
    while(head != NULL)
    {
        printf("%d ",head->val);
        head = head->next;
    }
    printf("END\n");
    return;
}
/***************************** Alternate reverse nodes of a list ****************/

void reverse(Node **head)
{
    Node *prev = NULL;
    Node *curr = *head;
    Node *next;
    while(curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    (*head) = prev;
}

Node* reverseSection(Node *head,int k)
{
    Node *prev = NULL;
    Node *curr = head;
    Node *next = NULL;
    int count = 0;
    while(curr != NULL && count < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    if(next != NULL){head->next = reverseSection(next,k);}
    return prev;
}

int main()
{
    Node *head = NULL;
    int i=0;
    for(i=0;i<10;i++)
    {
        push(&head,i);
    }
    head = reverseSection(head,7);
    print(head);
}
