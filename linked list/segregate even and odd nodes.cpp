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
node* segregate(node* head)
{
    if(head==NULL||head->next==NULL)
    {
        return head;
    }
    node*evenhead,*eventail,*oddhead,*oddtail;
    evenhead=NULL;
    eventail=NULL;
    oddhead=NULL;
    oddtail=NULL;
    node* temp=head;
    while(temp!=NULL)
    {
        if((temp->data)%2==0&&evenhead==NULL)
        {
            evenhead=temp;
            eventail=temp;
        }
        else if((temp->data)%2==0&&evenhead!=NULL)
        {
            eventail->next=temp;
            eventail=eventail->next;

        }
        if((temp->data)%2!=0&&oddhead==NULL)
        {
            oddhead=temp;
            oddtail=temp;
        }
        else if((temp->data)%2!=0&&oddhead!=NULL)
        {
            oddtail->next=temp;
            oddtail=oddtail->next;
        }
            temp=temp->next;
    }
    if(evenhead==NULL)
    {
        return head;
    }
    if(oddhead==NULL)
    {
        return head;
    }
    eventail->next=oddhead;
    oddtail->next=NULL;
    return evenhead;
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
    node* head=NULL;
    head=insertatlast(head,1);
    head=insertatlast(head,2);
    head=insertatlast(head,3);
    head=insertatlast(head,4);
    head=insertatlast(head,5);
    head=insertatlast(head,6);
    head=insertatlast(head,7);
    head=insertatlast(head,8);
    printclockwise(head); 
    cout<<endl;
    head=segregate(head);
    printclockwise(head); 
}

// we use 4 pointer to keep track of even and odd node head and tail we if it is even we keep adding node at the end of the
// even tail and if it is odd we keep on adding nodes at the end of the odd tail
// and at last we join even tail with odd head and make odd tail next NULL so that we can stop there while traversal 