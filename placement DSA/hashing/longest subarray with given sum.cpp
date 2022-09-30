#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    for(auto &x:a)cin>>x;
    unordered_map<int,int>mp;
    int sum=0;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        sum+=a[i];
        if(sum==k)
        {
            ans=i+1;
        }
        if(mp.find(sum)==mp.end())
        {
            mp.insert({sum,i});
        }
        if(mp.find(sum-k)!=mp.end())
        {
            ans=max(ans,i-mp[sum-k]);
        }
    }
    cout<<ans;
}