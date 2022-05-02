#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct node
{
    int data;
    node* next;
    node(int data)
    {
        this->data=data;
        next=NULL;
    }
};
struct mystack
{
    node* head;
    int size;
    mystack()
    {
        head=NULL;
        size=0;
    }
    void push(int data)
    {
        node* ptr=new node(data);
        if(head==NULL)
        {
            head=ptr;
            size++;
            return ;
        }
        ptr->next=head;
        head=ptr;
        size++;
        return ;
        
    }
    void pop()
    {
        if(size==0)
        {
            cout<<"stack is empty"<<endl;
            return ;
        }
        node* temp=head;
        head=head->next;
        delete(temp);
        size--;
        return ;
    }
    int top()
    {
        if(size==0)
        {
            cout<<"stack is empty"<<endl;
            return INT_MAX;
        }
        return head->data;
    }
    bool empty()
    {
        return size==0;
    }
    int ssize()
    {
        return size;
    }

};

int main()
{
    mystack s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout<<"the size of stack is "<<s.ssize()<<endl;
    while(!s.empty())
    {
        cout<<s.top()<<endl;
        s.pop();
    }
    cout<<"the size of stack is "<<s.ssize()<<endl;
}