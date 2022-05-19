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
    stack<node*>s1,s2;
    s1.push(root);
    while(!s1.empty()||!s2.empty())
    {
        while(!s1.empty())
        {
            node* temp=s1.top();
            s1.pop();
            cout<<temp->data<<endl;
            if(temp->left!=NULL)
            s2.push(temp->left);
            if(temp->right!=NULL)
            s2.push(temp->right);
        }
        while(!s2.empty())
        {
            node* temp=s2.top();
            s2.pop();
            cout<<temp->data<<endl;
            if(temp->right!=NULL)
            s1.push(temp->right);
            if(temp->left!=NULL)
            s1.push(temp->left);
        }
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
// the logic behind is to use 2 stack first push the node into 1st stack and then traverse the first stack and  print the top element and push their left and right child 
// into the other stack in left to right order so that for the next level last one will be at the top and after that traverse the second
// stack and then keep printing the top element and keep pushing the right and left children into the other stack(1st) in this stack 
// first push the right and then the left child because for the next level it will print inorder so it needs left node at the top