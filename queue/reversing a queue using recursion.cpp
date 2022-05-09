#include<bits/stdc++.h>
#define ll long long
using namespace std;
void reverse(queue<int>&q)
{
    if(q.empty())
    {
        return ;
    }
    int x=q.front();    
    q.pop();   // remove the first element 
    reverse(q);  // call reverse for remaining queue
    q.push(x); // then push the removed element at the last
}
int main()
{
    int n;
    cin>>n;
    queue<int>q;
    while(n--)
    {
        int x;
        cin>>x;
        q.push(x);
    }
    queue<int>d=q;
    cout<<"queue before reverse"<<endl;
    while(!d.empty())
    {
        cout<<d.front()<<endl;
        d.pop();
    }
    reverse(q);
    cout<<"queue after reverse"<<endl;
    while(!q.empty())
    {
        cout<<q.front()<<endl;
        q.pop();
    }
}

// the idea behind this solution is that assume we have reversed the queue for the n-1 elements and for the 1st element what we
// do is we first remove the first element then reverse the remaining queue and then after reversing we push the first item at last
