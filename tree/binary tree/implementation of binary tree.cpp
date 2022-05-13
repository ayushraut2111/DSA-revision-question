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
void inordertraversal(node*root)
{
    if(root==NULL)
    return;
    inordertraversal(root->left);
    cout<<root->data<<endl;
    inordertraversal(root->right);
}

int main()
{
    node* root=NULL;
    root=insert(root,1);
    root=insert(root,2);
    root=insert(root,3);
    inordertraversal(root);

}