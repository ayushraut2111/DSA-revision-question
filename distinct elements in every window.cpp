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
    for(int i=0;i<k;i++)
    {
        mp[a[i]]++;
    }
    cout<<mp.size()<<" ";
    for(int i=k;i<n;i++)
    {
        mp[a[i-k]]--;
        if(mp[a[i-k]]==0)
        {
            mp.erase(a[i-k]);
        }
        mp[a[i]]++;
        cout<<mp.size()<<" ";
    }
}