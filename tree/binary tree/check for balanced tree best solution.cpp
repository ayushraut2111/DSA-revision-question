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
int balancedtree(node* root)   // its time complexity if nlog(n)
{
     if(root==NULL)
    {
        return 0;
    }
    int leftheight=balancedtree(root->left);
    int rightheight=balancedtree(root->right);
    if(leftheight!=-1&&rightheight!=-1&&abs(leftheight-rightheight)<=1)
    {
    return max(leftheight,rightheight)+1;
    }
    else
    return -1;
}
int main()
{
    node* root=NULL;
    root=insert(root,1);
    root=insert(root,2);
    root=insert(root,2);
    root=insert(root,2);
//    root->left->left=new node(3);
    balancedtree(root)!=-1?cout<<"yes":cout<<"no";
}


// the idea behind this approach is to change the height finding function if the tree is balanced then return its height else return -1