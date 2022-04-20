#include<bits/stdc++.h>
using namespace std;
void frequencies(int a[],int n)
{
    map<int,int>mp;
    for(int i=0;i<n;i++)
    {
        if(mp.find(a[i])!=mp.end())
        {
            mp[a[i]]++;
        }
        else
        mp[a[i]]=1;
    }
    for(auto it=mp.begin();it!=mp.end();it++)
    {
        cout<<it->first<<" "<<it->second<<endl;
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
    frequencies(a,n);
}