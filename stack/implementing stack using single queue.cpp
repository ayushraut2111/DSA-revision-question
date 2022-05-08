#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct mystack
{
    queue<int>q;
    int size;
    mystack()
    {
        size=0;
    }
    void pushh(int x)
    {
        if(q.empty())
        {
            q.push(x);
            size++;
            return ;
        }
        q.push(x);
        size++;
        int temp=size-1;
        while(temp--)
        {
            int s=q.front();
            q.pop();
            q.push(s);
        }
        return ;
    }
    void popp()
    {
        q.pop();
        size--;
        return ;
    }
    int topp()
    {
        return q.front();
    }
};
int main()
{
    mystack s;
    s.pushh(1);
    s.pushh(2);
    cout<<s.topp()<<endl;
    s.pushh(3);
    cout<<s.topp()<<endl;
    s.popp();
    cout<<s.topp()<<endl;
    cout<<s.size<<endl;
    
}

// the idea behind solcing this problem is to consider the no of elements in  queue, we have to put inserted elements always at the top
// so first push the element in the queue and then pop front elements of the queue and push at the back again by this approach we can implemeny stack using queue
// but the push operation will become costly
