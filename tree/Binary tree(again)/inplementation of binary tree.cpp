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
node* deletelast(node* root,node* ptr)
{
    if(root==NULL)
    {
        return root;
    }
    queue<node*>q;
    q.push(root);
    while(!q.empty())
    {
        node* temp=q.front();
        q.pop();
        if(temp->right!=NULL)
        {
            if(temp->right==ptr)
            {
                temp->right=NULL;
                delete(ptr);
                return root;
            }
            else
            {
                q.push(temp->right);
            }
        }
        if(temp->left!=NULL)
        {
            if(temp->left==ptr)
            {
                temp->left=NULL;
                delete(ptr);
                return root;
            }
            else
            {
                q.push(temp->left);
            }
        }
    }
}
node* deletekey(node* root,int data)
{
    if(root==NULL)
    {
        cout<<"tree is empty"<<endl;
        return NULL;
    }
    queue<node*>q;
    q.push(root);
    node*datakey,*ptr;
    while(!q.empty())
    {
        ptr=q.front();
        q.pop();
        if(ptr->data==data)
        {
            datakey=ptr;
        }
        if(ptr->left!=NULL)
        {
            q.push(ptr->left);
        }
        if(ptr->right!=NULL)
        {
            q.push(ptr->right);
        }
    }

    int x=ptr->data;
    root=deletelast(root,ptr);
    if(ptr!=datakey) // this condition is used to handle if last node is the node which is to be deleted
    datakey->data=x;
    return root;
}
int main()
{
    node* root=NULL;
    root=insert(root,1);
    root=insert(root,2);
    root=insert(root,3);
    levelorder_traversal(root);
    cout<<endl;
    // searchtree(root,7)?cout<<"key found":cout<<"key not found"<<endl;
    root=deletekey(root,3);
    levelbyleveltraversal(root);
}