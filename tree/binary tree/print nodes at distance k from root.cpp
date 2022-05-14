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
void printk(node* root,int k)
{
    queue<node*>q;
    q.push(root);
    int count=0;
    while(!q.empty()&&count!=k)   
    {
        int size=q.size();
        for(int i=0;i<size;i++){  // if we want all the nodes of the level at once then we use for loop because queue will only left with nodes at that level only
        node* temp=q.front();
        q.pop();
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
    while(!q.empty())
    {
        cout<<q.front()->data<<endl;
        q.pop();
    }
}
void printkrecursive(node* root,int k)  //in recursive solution we go to left left untill the k dist is achieved then we print left one and then we go to right and print it
{
    if(root==NULL)
    {
        return ;
    }
    if(k==0)
    {
        cout<<root->data<<endl;
    }
    else
    {
        printkrecursive(root->left,k-1);
        printkrecursive(root->right,k-1);

    }
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
    printkrecursive(root,2);
}