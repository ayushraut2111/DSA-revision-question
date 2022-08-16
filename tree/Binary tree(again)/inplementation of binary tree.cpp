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
void preorder(node* root)
{
    if(root==NULL)
    return ;
    cout<<root->data<<endl;
    preorder(root->left);
    preorder(root->right);
}
void postorder(node* root)
{
    if(root==NULL)
    return ;
    preorder(root->left);
    preorder(root->right);
    cout<<root->data<<endl;
}
void inorder(node* root)
{
    if(root==NULL)
    return ;
    preorder(root->left);
    cout<<root->data<<endl;
    preorder(root->right);
}
void levelorder_traversal(node* root)
{
    if(root==NULL)
    {
        cout<<"tree is empty"<<endl;
        return ;
    }
    queue<node*>q;
    q.push(root);
    while(!q.empty())
    {
        node* temp=q.front();
        q.pop();
        cout<<temp->data<<endl;
        if(temp->left!=NULL)
        {
            q.push(temp->left);
        }
        if(temp->right!=NULL)
        {
            q.push(temp->right);
        }
    }
}
void levelbyleveltraversal(node* root)
{
    if(root==NULL)
    {
        cout<<"tree is empty"<<endl;
        return ;
    }
    queue<node*>q;
    q.push(root);
    while(!q.empty())
    {
        int size=q.size();
        for(int i=0;i<size;i++)
        {
            node* temp=q.front();
            q.pop();
            cout<<temp->data<<endl;
            if(temp->left!=NULL)
            {
                q.push(temp->left);
            }
            if(temp->right!=NULL)
            {
                q.push(temp->right);
            }
        }
    }
}
bool searchtree(node* root,int data)
{
    if(root==NULL)
    {
        cout<<"tree is empty"<<endl;
        return false;
    }
    queue<node*>q;
    q.push(root);
    while(!q.empty())
    {
        node* temp=q.front();
        q.pop();
        if(temp->data==data)
        {
            return true;
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
    return false;
}
int main()
{
    node* root=NULL;
    root=insert(root,1);
    root=insert(root,2);
    root=insert(root,3);
    levelorder_traversal(root);
    cout<<endl;
    searchtree(root,7)?cout<<"key found":cout<<"key not found"<<endl;
}