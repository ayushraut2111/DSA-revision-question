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
void spiraltraversal(node* root)
{
    if(root==NULL)
    {
        cout<<"tree is empty"<<endl;
        return ;
    }
    queue<node*>q;
    q.push(root);
    int m=0;
    stack<int>s;
    while(!q.empty())
    {
        int size=q.size();
        for(int i=0;i<size;i++)
        {
            node* temp=q.front();
            q.pop();
            if(m%2==0)
            {
                cout<<temp->data<<endl;
            }
            else
            {
                s.push(temp->data);
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
        if(m%2!=0)
        {
            while(!s.empty())
            {
                cout<<s.top()<<endl;
                s.pop();
            }
        }
            m++;
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
    root=insert(root,6);
    root=insert(root,7);
    root=insert(root,8);
    root=insert(root,9);
    root=insert(root,10);
    spiraltraversal(root);
}

// the logic behind this is traverse simply levelwise if it is odd level then print it else push it into the stack and after the level is traversed if it is odd level then print the stack