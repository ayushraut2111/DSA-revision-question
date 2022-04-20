#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node* next;
    node(int x)
    {
        data=x;
        next=NULL;
    }
};
node* insertatlast(node* head,int x)
{
    node* ptr=new node(x);
    if(head==NULL)
    {
        head=ptr;
        return head;
    }
    else
    {
        node* temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=ptr;
        return head;
    }
}
node* mergetwolist(node* h1,node* h2)
{
    if(h1==NULL&&h2!=NULL)
    return h2;
    if(h2==NULL&&h1!=NULL)
    return h1;
    node* head=NULL,*tail=NULL;
    while(h1!=NULL&&h2!=NULL)
    {
        if(h1->data>h2->data&&head==NULL)
        {
            head=h2;
            tail=h2;
            h2=h2->next;
        }
        else if(h1->data>h2->data)
        {
            tail->next=h2;
            tail=h2;
            h2=h2->next;
        }
        else if(h2->data>h1->data&&head==NULL)
        {
            head=h1;
            tail=h1;
            h1=h1->next;
        }
        else
        {
            tail->next=h1;
            tail=h1;
            h1=h1->next;
        }
    }
    if(h1==NULL)
    {
        while(h2!=NULL)
        {
            tail->next=h2;
            tail=h2;
            h2=h2->next;
        }
    }
    if(h2==NULL)
    {
        while(h1!=NULL)
        {
            tail->next=h1;
            tail=h1;
            h1=h1->next;
        }
    }
    return head;
}
void printclockwise(node* head)
{
    node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<endl;
        temp=temp->next;
    }
}
int main()
{
    node* h1=NULL,*h2=NULL;
    h1=insertatlast(h1,4);
    h1=insertatlast(h1,5);
    h1=insertatlast(h1,6);
    // h1=insertatlast(h1,35);
    h2=insertatlast(h2,1);
    h2=insertatlast(h2,2);
    h2=insertatlast(h2,10);
    node* head=mergetwolist(h1,h2);
    printclockwise(head);
}

// the idea is to make a two pointer and keep addng the small node to the tail pointer(tail) if a node is added to the tail pointer 
// then move the pointer to the next of it