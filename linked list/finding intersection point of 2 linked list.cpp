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
node* intersect(node* h1,node* h2)
{
    int c1=0,c2=0;
    node* temp=h1;
    while(temp!=NULL)
    {
        c1++;
        temp=temp->next;
    }
    temp=h2;
    while(temp!=NULL)
    {
        c2++;
        temp=temp->next;
    }
    int count=abs(c1-c2);
    if(c1>c2)
    {
    while(count--)
    {
        h1=h1->next;
    }
    }
    else
    {
        while(count--)
        {
            h2=h2->next;
        }
    }
    while(h1!=NULL&&h2!=NULL)
    {
        if(h1==h2)
        {
            return h1;
        }
        h1=h1->next;
        h2=h2->next;
    }
    return NULL; 
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
    node* head1=NULL;
    head1=insertatlast(head1,1);
    head1=insertatlast(head1,2);
    head1=insertatlast(head1,3);
    head1=insertatlast(head1,4);
    head1=insertatlast(head1,5);
    head1=insertatlast(head1,6);
    head1=insertatlast(head1,7);
    head1=insertatlast(head1,8);
    node* head2=NULL;
    head2=insertatlast(head2,11);
    head2=insertatlast(head2,22);
    head2->next->next=head1->next->next->next->next;
    printclockwise(head1);
    cout<<endl;
    printclockwise(head2);
    cout<<endl;
    node* temp=intersect(head1,head2);
    cout<<"intersection point is "<<temp->data<<endl;
}

// 1st method is to put all the nodes of first list in the hash table then traverse the second list and when we get the first 
//node we return it as it will be the intersection point of it 

// 2nd method is to first find the size difference between two lists so that we know how much one is greater than other 
// then we traverse the bigger list that number of times so that now bot list have same size to traverse
// then traverse both list simultaneously as now they both have same size so their intersection point is at the same distance 
// because after the intersection point they both have same number of elements
// so traverse them simultaneously will give the intersection point in same distance