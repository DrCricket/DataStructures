#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<stack>
#include<cmath>

using namespace std;

typedef struct Tree
{
	int val;
 	struct Tree *left;
	struct Tree *right;
}Tree;

int vertiDist(Tree *head,int a);

void insert(Tree **t,int n)
{
	if(*t == NULL)
	{
		*t = (Tree *)malloc(sizeof(Tree));
		(*t)->left = NULL;
		(*t)->right = NULL;
		(*t)->val = n;
		return;
	}
	while(*t != NULL)
	{
		if(n > (*t)->val)
		{
			t = &((*t)->right);
		}
		else
		{
			t = &((*t)->left);
		}
	}
	Tree* l = (Tree*)malloc(sizeof(Tree));
	l->val = n;
	l->left = NULL;
	l->right = NULL;
	*t = l;
	return;
}
/**************************** Inorder Traversal *****************************************/

void inord(Tree *head)
{
    if(head = NULL){return;}
    inord(head->left);
    cout << head->val << " " << endl;
    inord(head->right);
}
/*********************** Reverse alternate levels of a binary tree ******************/
void inorder(Tree *head,stack<int> *s,int l);
void revInsert(Tree *head,stack<int> *s,int l);

void revAlt(Tree *head)
{
    stack<int> s;
    inorder(head,&s,0);
    revInsert(head,&s,0);
}

void inorder(Tree *head,stack<int> *s,int l) // Collect all odd level order values
{
    if(head == NULL)
    {return ;}

    inorder(head->left,s,l+1);
    if(l%2 != 0)
    {
        (*s).push(head->val);
    }
    inorder(head->right,s,l+1);
}

void revInsert(Tree *head,stack<int> *s,int l)
{
    if(head == NULL)
    {return;}
    revInsert(head->left,s,l+1);
    if(l%2 != 0)
    {
        head->val = (*s).top();
        (*s).pop();
    }
    revInsert(head->right,s,l+1);
}


int main()
{

    Tree *head = NULL;
    insert(&head,10);
    insert(&head,15);
    insert(&head,5);
    insert(&head,2);
    insert(&head,7);
    insert(&head,12);
    insert(&head,18);
    insert(&head,1);
    insert(&head,3);
    insert(&head,6);
    insert(&head,8);
    insert(&head,11);
    insert(&head,14);
    insert(&head,16);
    insert(&head,20);
    inord(head);
    cout << endl;
    revAlt(head);
    inord(head);
    return 0;
}

