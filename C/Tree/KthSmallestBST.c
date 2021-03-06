#include<stdio.h>
#include<stdlib.h>

typedef struct Tree
{
	int val;
 	struct Tree *left;
	struct Tree *right;
}Tree;


void KthSmallestHelper(Tree *sr,int key,int *pos);

Tree* findLargest(Tree *t);
main()
{
//	Tree* findLargest(Tree *t);
	void insert(Tree **t,int n);
	void display(Tree *t);
	Tree* search(Tree *t, int n);
	void delete(Tree *t,int n);
	void inorder(Tree *t);
	void preorder(Tree *sr);
	void postorder(Tree *sr);
	void successor(Tree *sr,int t);
	void KthSmallest(Tree *sr,int k);



	int arr[10]= {1,2,3,5,6,4,7,9,8,0};

	Tree *t;
	t = NULL;
	int i;
	for(i=0;i<10;i++)
	{
		 insert(&t,arr[i]);
	}
	Tree *p;
	p = search(t,1);
	inorder(t);
	if(p == NULL)
	{
		printf("\n Not Found");
	}
	else
	{
		printf("\n (%d found)\n",p->val);
	}
	delete(t,5);
	delete(t,7);
	delete(t,0);
	inorder(t);
	printf("\n");
	//preorder(t);
	printf("\n");
	//postorder(t);
	printf("%dth smallest element: ",5);
	//KthSmallest(t,5);

	printf("\n");
	printf("Successor to %d is ",7);
	successor(t,7);

	return;
}

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

Tree* search(Tree *t,int n)
{
	Tree *p;
	p = t;
	while( p != NULL)
	{
		if(n > p->val)
		{
			p = p->right;
		}
		else if(n < p->val)
		{
			p = p->left;
		}
		else{
			return p;
		}
	}
	return p;
}

void delete(Tree *t,int n)
{

//	if( /*Tree has both left and right child*/)
//	if(/*Tree has only right child*/)
//	if(/*Tree has only right child*/)
//	if(/*Tree has no child*/)
		return;
}

Tree *findLargest(Tree *t)
{
	Tree *p = t;
	while(p->right != NULL)
	{
		p = p->right;
	}
	return p;
}
/*********************************** TRAVERSALS BEGIN **************************/

void inorder(Tree *sr )
{
    if ( sr != NULL )
    {
        inorder ( sr -> left ) ;
        printf ( "%d ", sr->val ) ;
        inorder ( sr->right ) ;
    }
    return;
}

void preorder(Tree *sr)
{
    if(sr!=NULL)
    {
        printf("%d ",sr->val);
        preorder(sr->left);
        preorder(sr->right);
    }
    return;
}

void postorder(Tree *sr)
{
    if(sr != NULL)
    {
        postorder(sr->left);
        postorder(sr->right);
        printf("%d ",sr->val);
    }
    return;
}
/********************** END OF TRAVERSALS ************************/


/************************** Kth Smallest Element ****************/

void KthSmallest(Tree *sr,int k)
{
    static int count =0;
    if(sr != NULL)
    {
        KthSmallest(sr->left,k);
        count++;
        if(k == count){printf("%d",sr->val);}
        KthSmallest(sr->right,k);
    }
}


/********************** Inorder Successor *********************/

void successor(Tree *sr,int t)
{
    int pos;
    KthSmallestHelper(sr,t,&pos);
    KthSmallest(sr,pos+1);
}

void KthSmallestHelper(Tree *sr,int key,int *pos) // Get position of element - Kth order
{
    static int count =0;
    if(sr != NULL)
    {
        KthSmallestHelper(sr->left,key,pos);
        count++;
        if(key == sr->val){*pos = *(&count);}
        KthSmallestHelper(sr->right,key,pos);
    }
}

/***************** Level Order Traversal *****************************/

void LOrderTraversal(Node *head)
{
    Node *curr = head;

}


