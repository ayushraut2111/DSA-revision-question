#include<bits/stdc++.h>
#define ll long long
using namespace std;
class myqueue{
    private:
    int size,cap;
    int *arr;
    public:
    myqueue(int cap)
    {
        this->cap=cap;
        size=0;
        arr=new int[cap];
    }
    void push(int x)
    {
        if(size==cap)
        {
            cout<<"queue is full"<<endl;
            return;
        }
        arr[size]=x;
        size++;
    }
    int pop()  // in this implementation only pop opeartion is costlier rest other opeartions are of constant time
    {
        if(size==0)
        {
            cout<<"queue is empty"<<endl;
            return -1;
        }
        if(size==1)
        {
            int x=arr[0];
            size--;
            return x;
        }
        int x=arr[0];
        for(int i=0;i<size-1;i++)   // in this implementation for pop operation we are moving every elements one position back 
        {
            arr[i]=arr[i+1];
        }
        size--;
        return x;
    }
    int qsize()
    {
        return size;
    }
    bool isempty()
    {
        return size==0;
    }
    int front()
    {
        return arr[0];
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
    cout<<q.front()<<endl;
    q.push(2);
    cout<<q.pop()<<endl;
    cout<<q.front()<<endl;
    q.pop();
    q.isempty()?cout<<"empty"<<endl:cout<<"not empty"<<endl;
}
