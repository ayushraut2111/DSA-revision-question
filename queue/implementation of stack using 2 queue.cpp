#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct mystack{
    queue<int>q1,q2;   // q1 will be our stack
    void pushh(int x)
    {
        if(q1.empty())
        {
            q1.push(x);
            return;
        }
        while(!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(x);
        while(!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
        return ;
    }
    void popp()
    {
        if(q1.empty())
        {
            cout<<"stack is empty"<<endl;
            return ;
        }
        q1.pop();
        return;
    }
    int top()
    {
        return q1.front();
    }
};
int main()
{
    mystack s;
    s.pushh(1);
    s.pushh(2);
    s.popp();
    cout<<s.top()<<endl;
}