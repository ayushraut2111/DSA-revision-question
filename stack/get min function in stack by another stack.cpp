#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct mystack
{
    stack<int>s1,s2;
    void pushh(int x)
    {
        if(s1.empty()||x<s2.top())
        {
            s1.push(x);
            s2.push(x);
            return ;
        }
        s1.push(x);
        return;

    }
    void popp()
    {
        if(s1.top()==s2.top())
        {
            s1.pop();
            s2.pop();
            return ;
        }
        s1.pop();
        return ;

    }
    int getmin()
    {
        return s2.top();
    }
};
int main()
{
    mystack s;
    s.pushh(6);
    cout<<s.getmin()<<endl;
    s.pushh(2);
    cout<<s.getmin()<<endl;
    s.pushh(1);
    s.pushh(4);
    cout<<s.getmin()<<endl;
    s.popp();
    cout<<s.getmin()<<endl;
    s.popp();
}