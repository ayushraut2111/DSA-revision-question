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
bool childrensum(node* root)
{
    if(root==NULL||root->left==NULL||root->right==NULL)
    return true;
    bool x=childrensum(root->left);
    bool y=childrensum(root->right);
    if(x&&y)
    {
        if(root->left->data+root->right->data==root->data)
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
    root=insert(root,20);
    root=insert(root,8);
    root=insert(root,12);
    root=insert(root,3);
    root=insert(root,5);
    root=insert(root,3);
    root=insert(root,9);
    childrensum(root)?cout<<"yes":cout<<"no";
}

// children sum property means sum of left and right child must be equal to its parent
// if root is null or its left or right is also null because if a---b is a node and b next is null then so for a b is true as it doesnt have next
// then check for a,s left and right if both are true then check for children sum property if it follows then return true else return false  