#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *dup;
    int visited; /*1,-1*/
}Node;

void reset(Node *head)
{
    Node *iter = head;
    while(iter->next != NULL)
    {
        iter->visited = -1;
        iter = iter->next;
    }
    iter = iter->next;
    iter->visited = -1;
    return;
}

void insert(Node **head,int t)
{
    Node *n;
    n = (Node*)malloc(sizeof(Node));
    n->next = (*head);
    n->dup = NULL;
    n->data = t;
    n->visited = -1;
    (*head) = n;

    Node *iter = n;
    if(iter->next != NULL)
    {
        iter = iter->next;
        while(iter != NULL)
        {
            if(iter->data == t)
            {
                n->dup = iter;
                break;
            }
            iter = iter->next;
        }
    }
    return;
}

void print(Node *head)
{
    Node *iter = head;
    printf("\n");
    while(iter->next != NULL)
    {

        if(iter->dup != NULL)
        {
            printf("%d",iter->data);
            printf("(%d) ",iter->dup->data);
        }
        else
        {
            printf("%d ",iter->data);
        }
        iter = iter->next;
    }
    printf("%d\n",iter->data);
}

void print_dup(Node *head)
{
    Node* iter = head;
    while(iter->next != NULL)
    {
        if(iter->visited == -1)
        {
            printf("%d->",iter->data);
            iter->visited = 1;
            Node *temp = iter->dup;
            while(temp != NULL)
            {
                printf("%d->",temp->data);
                temp->visited = 1;
                temp = temp->dup;
            }
            printf("NULL");
            printf("\n");
        }
        iter = iter->next;

    }
    printf("%d->NULL",iter->data);
}

void delete_dup(Node **head,int t)
{
    Node *iter = (*head);
    if(iter->next == NULL)
    {
        if(iter->data == t)
        {
            free(iter);
            (*head) = NULL;
            return;
        }
        else{return;}
    }
    while(iter->next != NULL)
    {
        if(iter->next->data == t)
        {
             Node *temp = iter->next;
             iter->next = temp->next;
             Node *dup = temp->dup;
             while(dup != NULL)
             {
                 Node *iter2 = iter;
                 while(iter2->next != dup)
                 {
                     iter2 = iter2->next;
                 }
                 free
             }
             free(temp);
        }
        iter = iter->next;
    }
    return;

}
int main()
{
    Node *head = NULL;
    int i=0;
    for(i=0;i<10;i++)
    {
        insert(&head,i);
        insert(&head,10-i);
    }
    delete_dup(&head,1);
    print_dup(head);

}
