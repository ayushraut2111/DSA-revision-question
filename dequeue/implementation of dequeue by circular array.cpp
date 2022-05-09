#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct dqueue{
    int *arr;
    int size,cap,front;
    dqueue(int cap)
    {
        this->cap=cap;
        arr=new int[cap];
        size=0;
        front=0;
    }
    int getrear()   // this will give the location of the rear item
    {
        return (front+size-1)%cap;
    }
    bool isfull()
    {
        return size==cap;
    }
    bool isempty()
    {
        return size==0;
    }
    void pushfront(int x)
    {
        if(isfull())
        {
            cout<<"dequeue is full"<<endl;
            return ;
        }
        front=(front-1+cap)%cap;
        arr[front]=x;
        size++;
    }
    void pushback(int x)
    {
        if(isfull())
        {
            cout<<"dequeue is full"<<endl;
            return ;
        }
        int rear=getrear();
        rear=(rear+1)%cap;
        arr[rear]=x;
        size++;
    }
    void popfront()
    {
        if(isempty())
        {
            cout<<"deqeue is empty"<<endl;
            return ;
        }
        front=(front+1)%cap;
        size--;
    }
    void popback()
    {
         if(isempty())
        {
            cout<<"deqeue is empty"<<endl;
            return ;
        }
        size--;
    }
    int getfront()
    {
        if(isempty())
        {
            cout<<"dequeue is empty"<<endl;
            return -1;
        }
        return arr[front];
    }
    int rear()
    {
         if(isempty())
        {
            cout<<"deqeue is empty"<<endl;
            return -1;
        }
        return arr[getrear()];
    }
};
int main()
{
    dqueue dq(5);
    dq.pushfront(1);
    dq.pushfront(2);
    dq.pushback(3);
    cout<<dq.rear()<<endl;
    dq.popfront();
    dq.popback();
}