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

void inorder(Tree *head)
{
    if(head == NULL){return;}
    inorder(head->left);
    cout << head->val << " " << endl;
    inorder(head->right);
}

/******************************* greater sum tree using reverse in order traversal *****************************************/



void grtr(Tree *head,int *sum)
{
    if(head == NULL){return;}

    grtr(head->right,sum);

    (*sum) = (*sum) + (head->val);
     head->val = (*sum) - (head->val);

    grtr(head->left,sum);
}


void greaterSum(Tree *head)
{
    int s = 0;
    grtr(head,&s);
    return;
}

/************************** Calculate sum and then pre order traversal ********************/

void Sum(Tree *head,int *sum)
{
    if(head == NULL){return ;}
    Sum(head->left,sum);
    (*sum) = (*sum) + head->val;
    Sum(head->right,sum);
}

void grtr2(Tree *head,int *s)
{
    if(head == NULL){return;}
    grtr2(head->left,s);
    (*s) = (*s) - head->val;
    head->val = (*s);
    grtr2(head->right,s);
}
void greaterSum2(Tree *head)
{
    int s = 0;
    Sum(head,&s);
    grtr2(head,&s);
    return;
}



int main()
{

    Tree *head = NULL;
    insert(&head,11);
    insert(&head,2);
    insert(&head,29);
    insert(&head,1);
    insert(&head,7);
    insert(&head,15);
    insert(&head,40);
    insert(&head,35);
    greaterSum2(head);
    inorder(head);
    return 0;
}
