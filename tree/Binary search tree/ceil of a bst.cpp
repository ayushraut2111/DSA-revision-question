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
    if(data<root->data)
    {
        root->left=insert(root->left,data);
    }
    else
    {
        root->right=insert(root->right,data);
    }
    return root;
}
node* ceil(node* root,int x)
{
    if(root==NULL)
    {
        cout<<"tree is empty"<<endl;
        return root;
    }
    node* res=NULL,*temp=root;
    while(temp!=NULL)
    {
        if(temp->data==x)
        return temp;
        else if(temp->data>x)
        {
            res=temp;
        temp=temp->left;

        }
        else
        {
            temp=temp->right;
        }
    }
    return res;
}
int main()
{
    node* root=NULL;
    root=insert(root,2);
    root=insert(root,1);
    root=insert(root,22);
    root=insert(root,23);
    cout<<ceil(root,1)->data;

}