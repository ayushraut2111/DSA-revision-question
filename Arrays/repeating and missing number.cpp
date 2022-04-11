#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int r,m;
    map<int,int>mp;
    for(int i=0;i<n;i++)
    {
       if(mp.find(a[i])==mp.end())
       mp[a[i]]=1;
       else
       mp[a[i]]++;

    }
    // for(auto it=mp.begin();it!=mp.end();it++)
    // {
    //     if(it->second==2)
    //     r=it->first;
    // }
    for(int i=1;i<=n;i++)
    {
        if(mp.find(i)==mp.end())
        {
            m=i;
        }
        else
        {
            if(mp[i]==2)
            r=i;
        }

    }
    cout<<r<<" "<<m<<endl;
}