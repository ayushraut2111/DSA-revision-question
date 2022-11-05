#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define ppi pair<int,int> 
int main()
{
    int n,k;
    cin>>n>>k;
    int a[n];
    map<int,int>mp;
    for(int i=0;i<n;i++)
    {
    cin>>a[i];
    mp[a[i]]++;
    }
    priority_queue<ppi,vector<ppi>,greater<ppi>>pq;
    vector<ppi>v;
    for(auto it=mp.begin();it!=mp.end();it++)
    { 
        v.push_back({it->second,it->first});
    }
    for(int i=0;i<k;i++)
    {   
        pq.push(v[i]);
    }
    for(int i=k;i<v.size();i++)
    {
        pq.push(v[i]);
        pq.pop();
    }
    while(!pq.empty())
    {
        cout<<pq.top().second<<endl;
        pq.pop();
    }
}