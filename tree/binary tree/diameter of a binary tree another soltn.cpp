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
int diameter(node* root,int &ans) 
{
    if(root==NULL)
    {
        return 0;
    }
    int lh=diameter(root->left,ans);
    int rh=diameter(root->right,ans);
    ans=max(ans,1+lh+rh);
    return max(lh,rh)+1;
}
int main()
{
    node* root=NULL;
    root=insert(root,1);
    root=insert(root,2);
    root=insert(root,3);
    root->right->right=new node(5);
    root->right->left=new node(4);
    root->right->left->left=new node(6);
    int ans=INT_MIN;
    diameter(root,ans);
    cout<<ans;
}

// the logic is to change the height funct compute left and right height for every node and use another integer to save our ans 
// for every node update the ans as max and return the height of the tree always 
// we update our answer in ans integer only

// in this approach we update the ans while calculating left and right height 