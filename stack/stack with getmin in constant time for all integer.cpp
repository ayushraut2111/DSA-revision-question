#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct mystack
{
    stack<int>s;
    int min;
    void pushh(int x)
    {
        if(s.empty())
        {
            s.push(x);
            min=x;
            return ;
        }
        if(x>=min)
        {
            s.push(x);
            return ;
        }
        if(x<=min)
        {
            s.push(2*x-min);
            min=x;
            return ;
        }
    }
    int popp()
    {
        if(s.top()<=min)
        {
            int temp=min;
            min=2*min-s.top();
            s.pop();
            return temp;
        }
        int temp=s.top();
        s.pop();
        return temp;
    }
    int getmin()
    {
        return min;
    }
};
int main()
{
    mystack s;
    s.pushh(-1);
    s.pushh(10);
    s.pushh(20);
    cout<<s.getmin()<<endl;
    s.pushh(2);
    s.popp();
    s.pushh(-6);
    s.pushh(4);
    cout<<s.getmin()<<endl;

}

// we push 2*x - min only when we are getting x minimum than min so this is always going to be less than or equal to x so x is going to be our new min