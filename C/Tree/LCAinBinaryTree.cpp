#include <iostream>
#include<vector>
using namespace std;

typedef struct Tree
{
    struct Tree *left, *right;
    int val;
}Tree;

Tree* newNode(int key)
{
    Tree *temp = new Tree;
    temp->val = key;
    temp->left = temp->right = NULL;
    return temp;
}

/************************* LCA using array traversal ******************/


bool findPath(Tree *head,int v,vector<int> &vec)
{
    if(head == NULL)
    {
        return false;
    }

    vec.push_back(head->val);
    if(head->val == v)
    {
        return true;
    }

    if(head->left&&findPath(head->left,v,vec) || head->right&&findPath(head->right,v,vec))
    {
        return true;
    }

    vec.pop_back();
    return false;
}

int LCA(Tree *head,int v1,int v2)
{
    vector<int> p1,p2;
    bool b1 = findPath(head,v1,p1);
    bool b2 = findPath(head,v2,p2);
    if( !b1 || !b2){return -1;}
    int i=0;
    for(i=0;i<p1.size() && i<p2.size();i++)
    {
        if(p1[i] != p2[i]){break;}
    }
    return p1[i-1];
}

int main()
{
    Tree* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    cout << "LCA(4, 5) = " << LCA(root, 4, 5);
    cout << "\nLCA(4, 6) = " << LCA(root, 4, 6);
    cout << "\nLCA(3, 4) = " << LCA(root, 3, 4);
    cout << "\nLCA(2, 4) = " << LCA(root, 2, 4);
    return 0;
}

