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
        if(x<min)
        {
            s.push(x-min);
            min=x;
            return ;
        }
    }
    int popp()
    {
        if(s.top()<0)
        {
            int temp=min;
            min=min-s.top();
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
    s.pushh(5);
    s.pushh(10);
    s.pushh(20);
    cout<<s.getmin()<<endl;
    s.pushh(2);
    s.popp();
    s.pushh(6);
    s.pushh(4);
    cout<<s.getmin()<<endl;

}