#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    vector<int>v(n);
    for(auto &x:v)cin>>x;
    priority_queue<int,vector<int>,greater<int>>pq;
    for(int i=0;i<=k;i++)
    {
        pq.push(v[i]);
    }
    int index=0;
    for(int i=k+1;i<n;i++)
    {
        v[index]=pq.top();
        pq.pop();
        pq.push(v[i]);
        index++;
    }
    while(!pq.empty())
    {
        v[index]=pq.top();
        pq.pop();
        index++;
    }
    for(auto x:v)
    cout<<x<<" ";
}