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
void kth_smallest(node* root,int k,int &count)
{
    if(root==NULL)
    return ;
    kth_smallest(root->left,k,count);
    count++;
    if(count==k)
    {
        cout<<root->data<<endl;
    }
    kth_smallest(root->right,k,count);
}
int main()
{
    node* root=NULL;
    root=insert(root,50);
    root=insert(root,20);
    root=insert(root,10);
    root=insert(root,100);
    root=insert(root,40);
    root=insert(root,70);
    root=insert(root,120);
    root=insert(root,4);
    root=insert(root,60);
    root=insert(root,80);
    int count=0;
    kth_smallest(root,3,count);

}