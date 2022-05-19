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
int maxtree(node* root)
{
    int ans=INT_MIN;
    if(root==NULL)
    return ans;
    queue<node*>q;
    q.push(root);
    while(!q.empty())
    {
        node* temp=q.front();
        q.pop();
        ans=max(ans,temp->data);
        if(temp->left!=NULL)
        {
            q.push(temp->left);
        }
        if(temp->right!=NULL)
        {
            q.push(temp->right);
        }
    }
    return ans;
}
int main()
{
    node* root=NULL;
    root=insert(root,323);
    root=insert(root,1);
    root=insert(root,2);
    root=insert(root,31);
    root=insert(root,34);
    cout<<maxtree(root);
}