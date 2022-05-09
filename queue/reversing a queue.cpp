#include<bits/stdc++.h>
#define ll long long
using namespace std;
void reverse(queue<int>&q)
{
    stack<int>s;
    while(!q.empty())
    {
        s.push(q.front());
        q.pop();
    }
    while(!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
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