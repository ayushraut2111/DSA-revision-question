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
int maxwidth(node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int res=0;
    queue<node*>q;
    q.push(root);
    while(!q.empty()) 
    {
        int size=q.size();  // at every level check for current level width which is the size of the queue as at the beginnning the queue will contain only that much node equal to nodes at that level
        res=max(res,size);
        for(int i=0;i<size;i++) 
        {
            node* temp=q.front();
            q.pop();
            if(temp->left!=NULL)
            {
                q.push(temp->left);
            }
            if(temp->right!=NULL)
            {
                q.push(temp->left);
            }
        }
    }
    return res;
}
int main()
{
    node* root=NULL;
    root=insert(root,1);
    root=insert(root,2);
    root=insert(root,3);
    root=insert(root,31);
    root=insert(root,34);
    root=insert(root,1);
    root=insert(root,2);
    root=insert(root,3);
    root=insert(root,31);
    root=insert(root,34);
    root=insert(root,1);
    root=insert(root,2);
    root=insert(root,3);
    root=insert(root,31);
    root=insert(root,34);
    root=insert(root,1);
    root=insert(root,2);
    root=insert(root,3);
    root=insert(root,31);
    root=insert(root,34);
    root=insert(root,34);
    root=insert(root,1);
    root=insert(root,2);
    root=insert(root,3);
    root=insert(root,31);
    root=insert(root,34);
    root=insert(root,34);
    root=insert(root,1);
    root=insert(root,2);
    root=insert(root,3);
    root=insert(root,31);
    root=insert(root,34);
    root=insert(root,34);
    root=insert(root,1);
    root=insert(root,2);
    root=insert(root,3);
    root=insert(root,31);
    root=insert(root,34);
    root=insert(root,34);
    root=insert(root,1);
    root=insert(root,2);
    root=insert(root,3);
    root=insert(root,31);
    root=insert(root,34);
    root=insert(root,34);
    root=insert(root,1);
    root=insert(root,2);
    root=insert(root,3);
    root=insert(root,31);
    root=insert(root,34);
    root=insert(root,34);
    root=insert(root,1);
    root=insert(root,2);
    root=insert(root,3);
    root=insert(root,31);
    root=insert(root,34);
    cout<<maxwidth(root);
}