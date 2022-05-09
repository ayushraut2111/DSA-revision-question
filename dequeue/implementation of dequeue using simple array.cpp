#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct dqueue{
    int *arr,size,cap;
    dqueue(int x)
    {
        cap=x;
        arr=new int[cap];
        size=0;
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
            return;
        }
        if(size==0)
        {
            arr[size]=x;
        size++;
        return ;
        }
        for(int i=size-1;i>=0;i--)
        {
            arr[i+1]=arr[i];
        }
        arr[0]=x;
        size++;
        return ;
    }
    void pushback(int x)
    {
        if(isfull())
        {
            cout<<"dequeue is full"<<endl;
            return;
        }
        arr[size]=x;
        size++;
        return ;
    }
    void popfront()
    {
        if(isempty())
        {
            cout<<"dequeue is empty"<<endl;
            return ;
        }
        for(int i=0;i<size-1;i++)
        {
            arr[i]=arr[i+1];
        }
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
        size--;
        return ;
    }
    int front()
    {
         if(isempty())
        {
            cout<<"dequeue is empty"<<endl;
            return -1;
        }
        return arr[0];
    }
    int rear()
    {
         if(isempty())
        {
            cout<<"dequeue is empty"<<endl;
            return -1;
        }
        return arr[size-1];
    }

};
int main()
{
     dqueue dq(5);
    dq.pushfront(1);
    dq.pushfront(2);
    dq.pushback(3);
    cout<<dq.front()<<endl;
    dq.popfront();
    dq.popback();
}