#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<cmath>

using namespace std;

typedef struct Tree
{
	int val;
 	struct Tree *left;
	struct Tree *right;
}Tree;


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

/*******************************  right view of a binary tree ******************************/

void printRecur(Tree *head,int maxlevel,int *level);

void printRight(Tree *head)
{
    int level=0;
    printRecur(head,1,&level);
}

void printRecur(Tree *head,int maxlevel,int *level)
{
    if(head == NULL)
    {
        return;
    }
    if(*level < maxlevel)
    {
        cout << head->val << endl;
        *level = maxlevel;
    }
    printRecur(head->right,maxlevel+1,level);
    printRecur(head->left,maxlevel+1,level);
}

/***************************** Difference alternate levels ************************/

int diff(Tree *head)
{
    if(head == NULL)
    {
        return 0;
    }
    else{return (head->val - diff(head->left)- diff(head->right));}
}
int main()
{
    Tree* head = NULL;
    insert(&head,5);
    insert(&head,1);
    insert(&head,8);
    insert(&head,0);
    insert(&head,2);
    insert(&head,6);
    insert(&head,9);
    insert(&head,11);
    cout << diff(head) << endl;
    //printRight(head);
}

