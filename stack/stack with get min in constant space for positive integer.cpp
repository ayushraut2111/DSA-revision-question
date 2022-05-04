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

// the idea behind solving this question is when we get the minimum number then current number then instead of pushing that umber we push
// min-x and then update the min as current number so while popping when we get negative number in stack it means this number is the 
// minimum number so we update the minimum to prev minimum because we are now poopint the cureent minimum so we update the 
// minimum as min- current popped element