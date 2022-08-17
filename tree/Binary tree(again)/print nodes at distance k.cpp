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
void printk(node* root,int k)
{
    if(root==NULL)
    {
        cout<<"tree is empty"<<endl;
        return ;
    }
    int count=0;
    queue<node*>q;
    q.push(root);
    while(!q.empty())
    {
        int size=q.size();
        for(int i=0;i<size;i++){
        node*temp=q.front();
        q.pop();
        if(count==k)
        {
            cout<<temp->data<<" ";
        }
        if(temp->left!=NULL)
        {
            q.push(temp->left);

        }
        if(temp->right!=NULL)
        {
            q.push(temp->right);
        }
        }
        count++;
    }
}
int main()
{
    node* root=NULL;
    root=insert(root,1);
    root=insert(root,2);
    root=insert(root,4);
    root=insert(root,5);
    root=insert(root,6);
    root=insert(root,7);
    root=insert(root,8);
    root=insert(root,9);
    printk(root,1);
}