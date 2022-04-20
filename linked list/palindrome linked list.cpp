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
bool palindrome1(node* head)
{
    stack<int>s;
    node* temp=head;
    while(temp!=NULL)
    {
        s.push(temp->data);
        temp=temp->next;
    }
    temp=head;
    while(temp!=NULL)
    {
        if(temp->data!=s.top())
        return false;
        s.pop();
        temp=temp->next;
    }
    return true;
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
bool palindrome2(node* head)
{
    if(head==NULL&&head->next==NULL)
    {
        return true;
    }
    node* slow=head,*fast=head;
    node* ptr;
    while(fast!=NULL&&fast->next!=NULL)
    {
        ptr=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    node*prev=NULL;
    node*curr=slow;
    node* next=NULL;
    while(curr!=NULL)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }   // we can also join two list after reversing by ptr->next=prev but for checking we are not joining them
    cout<<"after reversing the linked list looks like"<<endl;
    
    printclockwise(head);
    printclockwise(prev);
    node* temp=head;
    node* temp1=prev;
    while(temp!=NULL&&temp1!=NULL)
    {
        if(temp->data!=temp1->data)
        return false;
        temp=temp->next;
        temp1=temp1->next;
    }
    return true;
}
int main()
{
    node* head=NULL;
    head=insertatlast(head,1);
    head=insertatlast(head,2);
    head=insertatlast(head,5);
    head=insertatlast(head,4);
    head=insertatlast(head,2);
    head=insertatlast(head,1);
    printclockwise(head);
    cout<<endl;
    palindrome2(head)?cout<<"yes":cout<<"no";

}

// 1st method is to push all the elements into stack while traversing and then traverse again is the data is not equal then return false
// else return true


// 2nd method is to reverse a list from the mid and then check by loop whether they are equal or not
