#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    int data1;
    struct Node *add;
}Node;

Node *XOR(Node *a,Node *b)
{
    Node *n = (int)(a)^(int)(b);
        return ((int)(a) ^ (int) (b));
}

void Insert(Node **head,int t)
{
    Node *new = (Node*)malloc(sizeof(Node));
    new->data = t;
    new->add = XOR(*head,NULL);

    if( (*head) != NULL)
    {
        Node *next = XOR((*head)->add, NULL);
        (*head)->add = XOR(new,next);
    }
    *head = new;
}

void Print(Node *head)
{
    Node *prev = NULL;
    Node *curr = head;
    Node *next;

    while(curr != NULL)
    {
        printf("%d->",curr->data);
        next = XOR(prev,curr->add);
        prev = curr;
        curr = next;
    }
    printf("NULL");
}

int Exists(Node *head,int n)
{
    Node *next;
    Node *prev = NULL;
    Node *curr = head;
    while(curr != NULL)
    {
        if( n == curr->data)
        {
            return 0;
        }
        next = XOR(curr->add,prev);
        prev = curr;
        curr = next;
    }
    return -1;
}

void Delete(Node **head,int n)
{
    if(Exists(*head,n) == -1)
    {
        return;
    }

    Node *prev = NULL;
    Node *curr = *head;
    Node *next = XOR(prev,curr);

    while(next != NULL)
    {
        if( n == (curr)->data)
        {

        }

    }
    return;
}
int main()
{
    Node *head = NULL;
    Insert(&head,4);
    Insert(&head,17);
    Insert(&head,-1);
    Delete(&head,17);
    printf("\n");
    Print(head);
    printf("\n%d",Exists(head,-1));
    return 0;
}
