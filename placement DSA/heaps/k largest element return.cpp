
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++)
    {
    cin>>a[i];
    }
    priority_queue<int,vector<int>,greater<int>>pq;
    for(int i=0;i<k;i++)
    {
        pq.push(a[i]);
    }
    for(int i=k;i<n;i++)
    {
        pq.push(a[i]);
        pq.pop();  
    }
    vector<int>v;
    while(!pq.empty())
    {
        v.push_back(pq.top());
        pq.pop();
    }
    for(auto x:v)cout<<x<<endl;
}