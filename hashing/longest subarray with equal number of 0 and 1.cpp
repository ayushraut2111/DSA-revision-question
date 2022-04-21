#include<bits/stdc++.h>
using namespace std;
int longestequal(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        if(a[i]==0)
        {
            a[i]=-1;
        }
    }
    int presum=0,res=0;
    unordered_map<int,int>mp;
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
    cout<<longestequal(a,n);
}
// the idea behind this is to change every 0 to -1 and then finding the longest subarray with 0 sum with the same logic as longest
// subarray with given sum