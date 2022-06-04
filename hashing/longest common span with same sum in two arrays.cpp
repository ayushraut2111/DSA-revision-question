#include<bits/stdc++.h>
using namespace std;
int longestspan(int a[],int b[],int n)
{
    for(int i=0;i<n;i++)
    {
        a[i]-=b[i];
    }
    unordered_map<int,int>mp;
    int presum=0,res=0;
    for(int i=0;i<n;i++)
    {
        presum+=a[i];
        if(presum==0)
        {
            res=max(res,i+1);
        }
        if(mp.find(presum)==mp.end())
        {
            mp[presum]=i;
        }
        if(mp.find(presum)!=mp.end())
        {
            res=max(res,i-mp[presum]);
        }
    }
    return res;
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
    int b[n];
    for(int i=0;i<n;i++)
    {
    cin>>b[i];
    }
    cout<<longestspan(a,b,n);
}
// the idea behind solving this problem is to subtract the one array from another and we have to find the common sum span so when we 
// reduce one array from another and they both have same sum then their sum will be zero so after subtracting we have to find the 
// longest subaray with the zero sum in that reduced subarray.
