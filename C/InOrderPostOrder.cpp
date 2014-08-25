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


/********************************************************************/


Tree* reCreate(int arr[])
{
    int n = sizeof(arr)/sizeof(arr[0]);

    int inorder[n];
//    copy(begin(arr),end(arr),begin(inorder));
//    sort(begin(inorder),end(inorder));
    Tree* head = NULL;
    int h = arr[0];
    int i=0;
    for(i=0;i<n;i++)
    {
        if(arr[i] == h)
        {
            break;
        }
    }
    int j = i-1;
    i++;
    while(i != n || j != -1)
    {
        if(i != n)
        {insert(&head,i);}
        if(j != -1)
        {insert(&head,j);}
        i++;
        j--;
    }
    return head;
}

void levelOrder(Tree *head)
{
    if(head == NULL)
    {
        return;
    }
    queue<Tree *> s;
    s.push(head);
    while(!s.empty())
    {
        Tree *curr = s.front();
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
    Tree* head = NULL;
    int preOrder[11] = {10,5,3,2,4,15,12,18,17,16};
    int inOrder[11] = {1,2,3,4,5,10,12,15,16,17,18};

    int h = preOrder[0];
    int i=0;
    for(i=0;i<11;i++)
    {
        if(inOrder[i] == h)
        {
            break;
        }
    }
    int j = i-1;
    i++;
    while(i != 11 || j != -1)
    {
        if(i != 11)
        {insert(&head,inOrder[i]);}
        if(j != -1)
        {insert(&head,inOrder[j]);}
        i++;
        j--;
    }

    levelOrder(head);

}
