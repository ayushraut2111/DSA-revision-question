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
int max_width(node* root)
{
    if(root==NULL)
    {
        cout<<"tree is empty"<<endl;
        return INT_MIN;
    }
    int widht=INT_MIN;
    queue<node*>q;
    q.push(root);
    while(!q.empty())
    {
        int size=q.size();
        widht=max(widht,size);
        for(int i=0;i<size;i++)
        {
            node* temp=q.front();
            q.pop();
            if(temp->left!=NULL)
            q.push(temp->left);
            if(temp->right!=NULL)
            q.push(temp->right);
    }
}
return widht;
}
int main()
{
    node* root=NULL;
    root=insert(root,20);
    root=insert(root,8);
    root=insert(root,12);
    root=insert(root,8);
    root=insert(root,5);
    root=insert(root,5);
    root=insert(root,5);
    root=insert(root,5);
    root=insert(root,5);
    root=insert(root,5);
    root=insert(root,5);
    cout<<max_width(root)<<endl;
}