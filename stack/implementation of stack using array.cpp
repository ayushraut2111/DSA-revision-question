#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct mystack{
    int *arr;
    int cap;
    int top;
    mystack(int n)
    {
        cap=n;
        arr=new int[cap];
        top=-1;
    }
    void push(int n)
    {
        if(top==cap-1)
        {
            cout<<"overflow"<<endl;
            return ;
        }
        top+=1;
        arr[top]=n;
    }
    int pop()
    {
        if(top==-1)
        {
            cout<<"underflow"<<endl;
            return -1;
        }
        int temp=arr[top];
        top--;
        return temp;
    }
    int peek()
    {
        if(top==-1)
        {
            cout<<"stack is empty"<<endl;
            return -1;
        }
        return arr[top];
    }
    int size()
    {
        return top+1;   
    }
    bool isempty()
    {
        if(top==-1)
        {
            return true;
        }
        return false;
    }
};
int main()
{
    mystack s(5);
    s.push(1);
    s.push(2);
    cout<<s.size()<<endl;
    while(!s.isempty())
    {
        cout<<s.pop()<<endl;
    }
    cout<<s.size()<<endl;
}