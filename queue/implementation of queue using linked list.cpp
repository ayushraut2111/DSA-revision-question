#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct node{
    int data;
    node* next;
    node(int x)
    {
        data=x;
        next=NULL;
    }
};
struct myqueue{
    int size;
    node* head;
    myqueue()
    {
        size=0;
        head=NULL;
    }

    void push(int x)
    {
        node *ptr=new node(x);
        if(head==NULL)
        {
            head=ptr;
            size++;
            return ;
        }
        node* temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=ptr;
        size++;
        return ;
    }
    void pop()
    {
        if(head==NULL)
        {
            cout<<"list is empty"<<endl;
            return ;
        }
        if(head->next==NULL)
        {
            size--;
            delete(head);
            head=NULL;
            return ;
        }
        node* temp=head;
        head=head->next;
        size--;
        delete(temp);
        return ;
    }
    int front()
    {
        if(head==NULL)
        {
            cout<<"queue is empty"<<endl;
            return -1;
        }
        return head->data;
    }
    int qsize()
    {
        return size;
    }
    bool isempty()
    {
        return size==0;
    }
};

int main()
{
    myqueue q;
    q.push(1);
    q.push(2);
    cout<<q.front()<<endl;
    cout<<q.qsize()<<endl;
    q.pop();
    cout<<q.front()<<endl;   
    cout<<q.qsize()<<endl;
}