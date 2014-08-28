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
/*********************** Reverse alternate levels of a binary tree ******************/






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
    int a = 17, b = 6;
    printf(" %d and %d cousins: %d\n",a,b,cousins(head,a,b));
    return 0;
}

