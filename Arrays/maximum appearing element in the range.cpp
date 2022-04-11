#include<bits/stdc++.h>
using namespace std;
int maxappear(int a[],int b[],int n,map<int,int>&mp)
{
    for(int i=0;i<n;i++)
    {
        for(int j=a[i];j<=b[i];j++)
        {
            if(mp.find(j)!=mp.end())
            {
                mp[j]++;
            }
            else
            {
                mp[j]=1;
            }
        }
    }
    pair<int,int>p={-1,-1};
    for(auto it=mp.begin();it!=mp.end();it++)
    {
        if(it->second>p.second)
        {
            p.first=it->first;
            p.second=it->second;
        }
    }
    return p.first;
}
int main()
{
    int n;
    cin>>n;
    int a[n],b[n];
    for(int i=0;i<n;i++)
    {
    cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
    cin>>b[i];
    }
    map<int,int>mp;
    cout<<maxappear(a,b,n,mp)<<endl;
    for(auto it=mp.begin();it!=mp.end();it++)
    {
        cout<<it->first<<" "<<it->second<<endl;
    }
}
