#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct node{
    int data;
    node* left,*right;
    node(int x)
    {
        data=x;
        left=NULL;
        right=NULL;
    }
};
node* insert(node* root,int x)
{
    node* ptr=new node(x);
    if(root==NULL)
    {
        root=ptr;
        return root;
    }
    queue<node*>q;
    q.push(root);
    while(!q.empty())  
    {
        node* temp=q.front();
        q.pop();
        if(temp->left==NULL)
        {
            temp->left=ptr;
            break;
        }
        else
        {
            q.push(temp->left);
        }
        if(temp->right==NULL)
        {
            temp->right=ptr;
            break;
        }
        else
        {
            q.push(temp->right);
        }
    }
    return root;
}
int maxheight(node* root) 
{
    if(root==NULL)
    {
        return 0;
    }
    int leftheight=maxheight(root->left);
    int rightheight=maxheight(root->right);
    return max(leftheight,rightheight)+1;
}
bool balancedtree(node* root)
{
    if(root==NULL)
    {
        return true;
    }
    int x=maxheight(root->left);
    int y=maxheight(root->right);
    if(abs(x-y)<=1)
    {
       bool t= balancedtree(root->left);
       bool k=balancedtree(root->right);
       if(t&&k)
       return true;
       else
       return false;
    }
    else
    return false;
}
int main()
{
    node* root=NULL;
    root=insert(root,1);
    root=insert(root,2);
   root->left->left=new node(3);
    balancedtree(root)?cout<<"yes":cout<<"no";
}

// the idea behind this approach is to first find the height of left and right subtree and then check if its heightdiff is less than or equal to 1
// then we call for its left and right subtree recursively if both are also true then we return true else we return false 