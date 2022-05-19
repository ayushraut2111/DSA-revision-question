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
int diameter(node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int lh=maxheight(root->left);
    int rh=maxheight(root->right);
    int leftdia=diameter(root->left);
    int rightdia=diameter(root->right);
    return max(1+lh+rh,max(leftdia,rightdia));
}
int main()
{
    node* root=NULL;
    root=insert(root,1);
    root=insert(root,2);
    root=insert(root,3);
    root->right->right=new node(5);
    root->right->left=new node(4);
    root->right->left->left=new node(6);
    cout<<diameter(root);
}
// the idea behing this is to find left and right subtree height for every node and add left and right and 1 as diameter also uses current node also
// and then return the maximum of all three current node's dia left subtree dia and right subtree dia