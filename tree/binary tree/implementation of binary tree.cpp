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
    while(!q.empty())   // in the loop we only check for left and right not for the node itself because in the previous loop when we pushed it into the queue then we already checked for left and right it then we push it into the queue so if we put root checking condition in loop again then we are checking it twice
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
node* deletelastnode(node* root,node* ptr)  // this function is for deleting the last node
{
    if(root==NULL)
    {
        cout<<"tree is empty"<<endl;
        return root;
    }
    if(root==ptr)  // if root is the only node in the tree 
    {
        delete(root);
        return NULL;
    }
    queue<node*>q;
    q.push(root);
    while(!q.empty())
    {
        node* temp=q.front();
        q.pop();
        if(temp->right!=NULL)   // here we are checking the right node first because the last node is always at the right side so it will be convenient to check right side first
        {
            if(temp->right==ptr)
            {
                delete(ptr);
                return root;
            }
            else
            {
                q.push(temp->right);
            }
        }
        if(temp->left!=NULL)
        {
            if(temp->left==ptr)
            {
                delete(ptr);
                return root;
            }
            else
            {
                q.push(temp->left);
            }
        }
    }
    return root;
}
node* deletenode(node* root, int key)   // to delete the node first delete the last node and replace the data at the node which is to be deleted with the last node's data
{
    if(root==NULL)   // this function will find the last node and replace the data of node which is to be deleted with the data of last node
    {
        cout<<"tree is empty"<<endl;
        return root;
    }
    queue<node*>q;
    node* datanode,*ptr;   // datanode to save the node which is to be deleted and ptr for the last node 
    q.push(root);
    while(!q.empty())
    {
        ptr=q.front();
        q.pop();
        if(ptr->data==key)
        {
            datanode=ptr;
        }
        if(ptr->left!=NULL)
        {
            q.push(ptr->left);
        }
        if(ptr->right!=NULL)
        {
            q.push(ptr->right);
        }
    }
    int x=ptr->data; // this is the data which is to be replaced in the node to be deleted after deleting the last node 
    root=deletelastnode(root,ptr);
    datanode->data=x;
    return root;
}
void inordertraversal(node*root)
{
    if(root==NULL)
    return;
    inordertraversal(root->left);
    cout<<root->data<<endl;
    inordertraversal(root->right);
}
void preordertraversal(node* root)
{
    if(root==NULL)
    return;
    cout<<root->data<<endl;
    inordertraversal(root->left);
    inordertraversal(root->right);   
}
void postordertraversal(node* root)
{
    if(root==NULL)
    return;
    inordertraversal(root->left);
    inordertraversal(root->right);
    cout<<root->data<<endl;
}
void levelordertraversal(node* root)  // this traversal is done level by level also lnown as bfs
{
    if(root==NULL)
    {
        cout<<"tree is empty"<<endl;
        return ;
    }
    queue<node*>q;
    q.push(root);
    while(!q.empty())
    {
        node* ptr=q.front();
        q.pop();
        cout<<ptr->data<<endl;
        if(ptr->left!=NULL)
        {
            q.push(ptr->left);
        }
        if(ptr->right!=NULL)
        {
            q.push(ptr->right);
        }
    }
}
void levelbyleveltraversal(node*root)  // this is also level order traversal but this will do traversal by taking care of all the elements at every level
{
    if(root==NULL)
    {
        cout<<"tree is empty"<<endl;
        return ;
    }
    queue<node*>q;
    q.push(root);
    while(!q.empty())
    {
        int size=q.size(); // we are running a loop till size of that level because after we process every element at that level then the reamining node in the queue will be of next level so save the size at beginning so that we will traverse only the nodes of that level only after traversal only the nodes of next level will remain in the queue
        for(int i=0;i<size;i++)
        {
            node* temp=q.front();
            q.pop();
            cout<<temp->data<<endl;
            if(temp->left!=NULL)
            {
                q.push(temp->left);
            }
            if(temp->right!=NULL)
            {
                q.push(temp->right);
            }
        }

    }
}
bool searchtree(node* root,int key)
{
    if(root==NULL)
    {
        cout<<"tree is empty"<<endl;
        return false;
    }
    queue<node*>q;
    q.push(root);
    while(!q.empty())
    {
        node* temp=q.front();
        q.pop();
        if(temp->data==key)
        {
            return true;
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
    return false;
}
int main()
{
    node* root=NULL;
    root=insert(root,1);
    root=insert(root,2);
    root=insert(root,3);
    root=insert(root,31);
    root=insert(root,34);
    levelordertraversal(root);
    searchtree(root,21)?cout<<"found":cout<<"not found"<<endl;
}