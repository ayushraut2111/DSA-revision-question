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
node *iterative_insert(node* root,int data)
{
    node* ptr=new node(data);
    if(root==NULL)
    {
        root=ptr;
        return root;
    }
    node* temp=root,*parent=NULL;
    while(temp!=NULL)
    {
        parent=temp;
        if(data<temp->data)
        {
            temp=temp->left;
        }
        else
        {
            temp=temp->right;
        }
    }
    if(data<parent->data)
    parent->left=ptr;
    else
    parent->right=ptr;
    return root;
}
bool searchtree(node* root,int x)
{
    if(root==NULL)
    return false;
    if(x==root->data)
    return true;
    else if(x<root->data)
    searchtree(root->left,x);
    else
    searchtree(root->right,x);
}
node* getsuccessor(node* root)
{
    root=root->right;
    while(root!=NULL&&root->left!=NULL)
    {
        root=root->left;
    }
    return root;
}
node *delete_node(node* root,int x)
{
    if(root==NULL)
    return NULL;
    if(x<root->data)
    {
        root->left=delete_node(root->left,x);
    }
    else if(x>root->data)
    {
        root->right=delete_node(root->right,x);
    }
    else
    {
        if(root->left==NULL&&root->right==NULL)
        return NULL;
        if(root->left==NULL)
        return root->right;
        if(root->right==NULL)
        return root->left;
        else
        {
            node *succ=getsuccessor(root);
            root->data=succ->data;
            root->right=delete_node(root->right,succ->data);
            return root;
        }
    }
    return root;
}
void inorder(node* root)
{
    if(root==NULL)
    return ;
    inorder(root->left);
    cout<<root->data<<endl;
    inorder(root->right);
}
int main()
{
    node* root=NULL;
    root=insert(root,1);
    root=insert(root,2);
    root=insert(root,3);
    root=iterative_insert(root,-3);
    inorder(root);
    cout<<endl;
    searchtree(root,31)?cout<<"found":cout<<"not found";
    root=delete_node(root,-3);
    inorder(root);
}