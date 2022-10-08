#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct node{
    node* next;
    int data;
    node(int x)
    {
        next=NULL;
        data=x;
    }
};
node* insertatbegin(node* head,int x)
{
    node* ptr=new node(x);
    if(head==NULL)
    {
        return ptr;
    }
    ptr->next=head;
    head=ptr;
    return head;
}
void print(node* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<endl;
        head=head->next;
    }
}
int main()
{
    node* root=NULL;
    root=insertatbegin(root,1);
    root=insertatbegin(root,2);
    print(root);
}