#include<bits/stdc++.h>
#define ll long long
using namespace std;
class myqueue{
    private:
    int front,size,cap;
    int *arr;
    public:
    myqueue(int cap)
    {
        this->cap=cap;
        arr=new int[cap];
        size=0;
        front=0;
    }
    int getrear()
    {
        return (front+size-1)%cap;   // in circular array the rear will always be calculated from the front and it is always at the distance size-1 from the front
    }
    bool isfull()
    {
        return size==cap;
    }
    bool isempty()
    {
        return size==0;
    }

    void push(int x)
    {
        if(isfull())
        {
            cout<<"queue is full"<<endl;
            return ;
        }
        int rear=getrear();
        rear=(rear+1)%cap;
        arr[rear]=x;
        size++;
    }
    void pop()
    {
        if(isempty())
        {
            cout<<"queue is empty"<<endl;
            return ;
        }
        front=(front+1)%cap;
        size--;
    }
    int getfront()
    {
        if(isempty())
        {
            cout<<"queue is empty"<<endl;
            return -1;
        }
        return arr[front];
    }

    ~myqueue()
    {
        cout<<"end of the queue"<<endl;
    }
};
int main()
{
    myqueue q(4);
    q.push(1);
    q.push(2);
    cout<<q.getfront()<<endl;
    q.pop();
    cout<<q.getfront()<<endl;

}