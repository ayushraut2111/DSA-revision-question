#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    // priority_queue<int,vector<int>,greater<int>>pq;
    // int n,x,k;
    // cin>>n>>x>>k;
    // int a[n];
    // for(int i=0;i<n;i++)
    // {
    // cin>>a[i];
    // }
    // for(int i=0;i<n;i++)
    // {
    //     pq.push(abs(a[i]-x));
    // }
    // while(k--&&!pq.empty())
    // {
    //     cout<<pq.top()+x<<endl;
    //     pq.pop();
    // }
    priority_queue<int>pq;
    int n,x,k;
    cin>>n>>x>>k;
    int a[n];
    for(int i=0;i<n;i++)
    {
    cin>>a[i];
    }
    for(int i=0;i<k;i++)
    {
        pq.push(a[i]-x);
    }
    for(int i=k;i<n;i++)
    {
        pq.push(a[i]-x);
        pq.pop();
    }
    while(!pq.empty())
    {
        cout<<pq.top()+x<<endl;
        pq.pop();
    }
}