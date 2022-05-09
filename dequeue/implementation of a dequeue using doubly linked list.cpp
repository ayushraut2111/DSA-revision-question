#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct node{
    node*next,*prev;
    int data;
    node(int data)
    {
        this->data=data;
        next=NULL;
        prev=NULL;
    }
};
class dqueue
{
    private:
    node* front,*rear;   // we will maintain two pointer front for pushing at front and rear for pushing at rear
    int size;
    public:
    dqueue()
    {
        front=NULL;
        rear=front;
        size=0;
    }
    bool isempty()
    {
        return size==0;
    }
    void pushfront(int x)
    {
        node* ptr=new node(x);
        if(front==NULL)
        {
            front=ptr;
            rear=front;
            size++;
            return ;
        }
        ptr->next=front;
        front->prev=ptr;
        front=ptr;
        size++;
        return ;
    }
    void pushback(int x)
    {
        node* ptr=new node(x);
        if(front==NULL)
        {
            front=ptr;
            rear=front;
            size++;
            return ;
        }
        rear->next=ptr;
        ptr->prev=rear;
        rear=ptr;
        size++;
        return;
    }
    void popfront()
    {
        if(isempty())
        {
            cout<<"dequeue is empty"<<endl;
            return ;
        }
        if(front->next==NULL)
        {
            delete(front);
            front=NULL;
            rear=NULL;
            size--;
            return ;
        }
        node* temp=front;
        front=front->next;
        front->prev=NULL;
        size--;
        return ;
    }
    void popback()
    {
        if(isempty())
        {
            cout<<"dequeue is empty"<<endl;
            return ;
        }
        if(front->next==NULL)
        {
            delete(front);
            front=NULL;
            rear=NULL;
            size--;
            return ;
        }
        node* temp=rear;
        rear=rear->prev;
        rear->next=NULL;
        delete(temp);
        size--;
        return ;

    }
    int getfront()
    {
        if(isempty())
        {
            cout<<"dequeue is empty"<<endl;
            return -1;
        }
        return front->data;
    }
    int getrear()
    {
        if(isempty())
        {
            cout<<"dequeue is empty"<<endl;
            return -1;
        }
        return rear->data;
    }
    
};
int main()
{
    dqueue dq;
    dq.pushfront(1);
    dq.pushfront(2);
    dq.pushback(3);
    dq.popfront();
    dq.popback();
    cout<<dq.getfront()<<endl;
}