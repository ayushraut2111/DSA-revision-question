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
node* swapalist1(node* head)
{
    if(head==NULL||head->next==NULL)
    {
        return head;
    }
    node* prev=NULL,*curr=head,*next;
    int count=0;
    while(curr!=NULL&&count<2)    // first we will reverse a list in a size of k 
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        count++;
    }
    node* mainhead=swapalist1(curr);   // then call the recursion for remaining node
    head->next=mainhead;     // joining the prev head to the returned new head of the remaining nodes because till this point our original head is still intact
    return prev;
}
node* swapalist2(node* head)
{
    if(head==NULL||head->next==NULL)
    {
        return head;
    }
    node* temp=head;
    while(temp!=NULL&&temp->next!=NULL)
    {
        swap(temp->data,temp->next->data);
        temp=temp->next->next;
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
    head=swapalist2(head);
    printclockwise(head);
}

// 1st method is to reverse 2 number and call for the remaining list and then join list

// 2nd method is to run a loop and  swap the two data and move the next pointer to two positions ahead 