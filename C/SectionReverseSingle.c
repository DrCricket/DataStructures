#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
int data;
struct Node *next;
}Node;

void insert(Node **head,int t)
{
    Node *n = (Node *)malloc(sizeof(Node));
    n->data = t;
    n->next = *head;
    (*head) = n;
    return;
}

void print(Node *head)
{
    Node *iter = head;
    if(head == NULL)
    {
        printf("NULL\n");
        return;
    }
    while(iter->next != NULL)
    {
        printf("%d->",iter->data);
        iter = iter->next;
    }
    printf("%d\n",iter->data);
    return;
}

void reverse(Node **head)
{
    Node *result = NULL;
    Node *curr = *head;
    Node *next;
    while(curr != NULL)
    {
        next = curr->next;
        curr->next = result;
        result = curr;
        curr = next;
    }
    *head = result;
}
int length(Node *head)
{
    Node *iter = head;
    int i=0;
    while(iter != NULL)
    {
        iter = iter->next;
        i++;
    }
    return i;
}
void section_reverse(Node *head,int k)
{
    int steps = k/length(head);
    int i=0;
    for(i=0;i<steps;i=i+k)
    {
        reverse(&head);
    }

}

int main()
{
    Node *head = NULL;
    int i=0;
    for(i=0;i<10;i++)
    {
        //insert(&head,i);
    }
    print(head);
    printf("%d\n",length(head));
    reverse(&head);
    print(head);
}
