#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<queue>

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


/*************************Check if two trees are isomorphic *****************************/

bool isomorphic(Tree *n1,Tree *n2)
{
    if(n1 == NULL && n2 == NULL){return true;}
    if(n1 == NULL || n2 == NULL){return false;}
    if(n1->val != n2->val){return false;} //Important not to evaluate the true condition first

    bool value = (isomorphic(n1->left,n2->left)&&isomorphic(n1->right,n1->right) || isomorphic(n1->left,n2->right)&&isomorphic(n1->right,n2->left));
    return value;
}

int main()
{
    Tree *head1 = NULL;
    insert(&head1,8);
    insert(&head1,10);
    insert(&head1,3);
    insert(&head1,5);
    insert(&head1,4);
    insert(&head1,6);
    insert(&head1,1);
    insert(&head1,9);

    Tree *head2 = NULL;

    cout << isomorphic(head1,head2) << endl;
}
