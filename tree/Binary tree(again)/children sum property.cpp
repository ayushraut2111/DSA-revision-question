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
bool childsum(node* root)
{
    if(root==NULL)
    {
        return true;
    }
    if(root->left==NULL&&root->right==NULL)
    {
        return true;
    }
    int sum=0;
    if(root->left!=NULL)
    {
        sum+=root->left->data;
    }
    if(root->right!=NULL)
    {
        sum+=root->right->data;
    }
    if(root->data==sum)
    {
        return childsum(root->left)&&childsum(root->right);
    }
    return false;
}
int main()
{
    node* root=NULL;
    root=insert(root,20);
    root=insert(root,8);
    root=insert(root,12);
    root=insert(root,3);
    root=insert(root,5);
   
    childsum(root)?cout<<"true":cout<<"false";
}