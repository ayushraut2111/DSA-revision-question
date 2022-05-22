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
    if(root==NULL)
    return false;
    v.push_back(root);
    if(root->data==n)
    return true;
    bool x=findpath(root->left,v,n);
    bool y=findpath(root->right,v,n);
    if(x||y)
    {
        return true;
    }
    v.pop_back();
    return false;
}
int commonancestor(node* root,int x,int y)
{
    if(root==NULL)
    {
        cout<<"tree is empty"<<endl;
        return -1;

    }
    vector<node*>v1,v2;
    findpath(root,v1,x);
    findpath(root,v2,y);
    reverse(v1.begin(),v1.end());
    for(auto x:v1)
    {
        if(find(v2.begin(),v2.end(),x)!=v2.end())
        {
            return x->data;
        }
    }
    return -1;

}
int main()
{
    node* root=NULL;
    root=insert(root,1);
    root=insert(root,5);
    root=insert(root,6);
    root->left->left=new node(7);
    root->left->right=new node(2);
    root->left->left->left=new node(4);
    root->left->right->right=new node(8);
    root->left->right->left=new node(9);
    root->left->right->left->left=new node(3);
    cout<<commonancestor(root,3,8)<<endl;
}

// the logic behind this is to first find the paths of both the nodes and then finding the last common node and that will be the lowest common ancestor as it is coming at last
// so to find the last common just traverse the any one of the vector from last and return the first common node