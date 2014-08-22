#include<cstdio>
#include<iostream>
#include<queue>
#include<cstdlib>

using namespace std;

typedef struct Node
{
    struct Node *left;
    struct Node *right;
    int val;
}Node;

void add(Node **head,int n)
{

    while(*head != NULL)
    {
        if( (*head)->val > n)
        {
            head = &((*head)->left);
        }
        else{head = &((*head)->right);}
    }
    (*head) = (Node *)malloc(sizeof(Node));
    (*head)->val = n;
    (*head)->left = NULL;
    (*head)->right = NULL;
    return;
}

void inorder(Node *head)
{
    if(head != NULL)
    {
        inorder(head->left);
        printf("%d ",head->val);
        inorder(head->right);
    }
    return;
}

void levelOrder(Node *head)
{
    if(head == NULL)
    {
        return;
    }
    queue<Node *> s;
    s.push(head);
    while(!s.empty())
    {
        Node *curr = s.front();
        s.pop();
        printf("%d ",curr->val);
        if(curr->left != NULL)
        {
                s.push(curr->left);
        }
        if(curr->right != NULL)
        {
            s.push(curr->right);
        }
    }

}
int main()
{
    Node *head = NULL;
    int i=0;
    add(&head,7);
    add(&head,5);
    add(&head,6);
    add(&head,8);

    printf("\n");
    levelOrder(head);
}
