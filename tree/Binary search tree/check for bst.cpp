#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct node{
    int data;
    node* left,*right;
    node(int data)
    {
        this->data=data;
        left=NULL;
        right=NULL;
    }
};
node* insert(node* root,int data)
{
    node* ptr=new node(data);
    if(root==NULL)
    {
        root=ptr;
        return root;
    }
    if(data<root->data)
    {
        root->left=insert(root->left,data);
    }
    else
    {
        root->right=insert(root->right,data);
    }
    return root;
}
bool isBST(node* root)
{
    if(root==NULL)
    return true;
    if(root->left!=NULL&&root->data<root->left->data)
    {
        return false;
    }
    if(root->right!=NULL&&root->data>root->right->data)
    return false;
    if(!isBST(root->left)||!isBST(root->right))
    return false;
    return true;
}
int main()
{
    node* root=NULL;
    root=insert(root,50);
    root->right=new node(10);
    // root=insert(root,10);
    // root=insert(root,100);
    // root=insert(root,40);
    // root=insert(root,70);
    // root=insert(root,120);
    // root=insert(root,4);
    // root=insert(root,60);
    // root=insert(root,80);
    isBST(root)?cout<<"yes":cout<<"no";
}