#include<bits/stdc++.h>
using namespace std;
void freq(int a[],int n,map<int,int>&mp)
{
    for(int i=0;i<n;i++)
    {
        if(mp.find(a[i])!=mp.end())
        {
            mp[a[i]]++;
        }
        else
        {
            mp[a[i]]=1;
        }
    }
}
void frequency(int a[],int n,vector<pair<int,int>>&v)
{
    int count=1;
    for(int i=0;i<n-1;i++)
    {
        int j=i+1;
        if(a[i]==a[j])
        {
            count++;
        }
        else
        {
            v.push_back({a[i],count});
            count=1;
        }
    }
    if(a[n-1]==a[n-2])
    {
        v.push_back({a[n-1],count});
    }
    else
    {
        v.push_back({a[n-1],1});
    }
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
    cin>>a[i];
    }
    map<int,int>mp;
    // freq(a,n,mp);
    // for(auto it=mp.begin();it!=mp.end();it++)
    // {
    //     cout<<it->first<<" "<<it->second<<endl;
    // }
    vector<pair<int,int>>v;
    frequency(a,n,v);
    for(auto x:v)
    {
        cout<<x.first<<" "<<x.second<<endl;
    }

}