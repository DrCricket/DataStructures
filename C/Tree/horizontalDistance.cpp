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
/***************************** Horizontal Distance ********************/


int dist(Tree *head,int k)
{
    Tree* curr = head;
    int dis = 0;
    while(curr->val != k)
    {
        if(curr->val > k)
        {
            curr = curr->left;
            dis++;
        }
        else
        {
            curr = curr->right;
            dis--;
        }
    }
    return dis;
}

int distBetween(Tree* head,int k,int l)
{
    int m = dist(head,k);
    int n = dist(head,l);
    if(m*n > 0)
    {
        return(abs(abs(m) - abs(n)));
    }
    else
    {
        return(abs(m) + abs(n));
    }

}
int main()
{
    Tree *head = NULL;
    insert(&head,10);
    insert(&head,15);
    insert(&head,5);
    insert(&head,3);
    insert(&head,12);
    insert(&head,18);
    insert(&head,17);
    insert(&head,16);
    insert(&head,2);
    insert(&head,4);
    insert(&head,1);
    insert(&head,6);
    int k = 10;
    int j = 12;
    cout << "Horizontal distance between " << k << " & " << j <<": "<<  distBetween(head,k,j) << endl;
    return 0;

}
