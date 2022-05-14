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
bool findpath(node* root,vector<node*>&v,int n)
{
    if(root==NULL)  // if the root is null that means we reached at the last so there is no node therefore return false
    return false;
    v.push_back(root);  // then push this node into the queue because if we found the node then current node is also in the path 
    if(root->data==n)  // if we got the index then return true
    {
        return true;
    }
    bool x=findpath(root->left,v,n); // check in left subtree and right subtree
    bool y=findpath(root->right,v,n);
    if(x||y)  // if any of the left and right subtree node is in the path then return true without popping as it is in the path
    {
        return true;
    }
    v.pop_back();  // if none of the left and right subtree node is in the path then remove it from the vector and then return false as it is never going to be in the path of the index
    return false;
}
int main()
{
    node* root=NULL;
    root=insert(root,1);
    root=insert(root,2);
    root=insert(root,3);
    root=insert(root,4);
    root=insert(root,5);
    root=insert(root,7);
    vector<node*>v;
    findpath(root,v,7);
    for(auto x:v)
    {
        cout<<x->data<<endl;
    }
}

// the idea is to keep pushing every node to vector untill the node is NULL or we find the index and keep on going on left and right side and then checking if any of the left or right side is true that
// means this node is in the path of the index if both are false that means no node is path of the index so pop it and then return false