#include<bits/stdc++.h>
#define ll long long
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
    unordered_set<int>s;
    for(int i=0;i<n;i++)
    {
        s.insert(a[i]);
    }
    int ans=1;
    int count=1;
    for(int i=0;i<n;i++)
    {
        if(s.find(a[i]-1)==s.end())
        {
            count=1;
        }
        else
        {
            count++;
        }
            ans=max(ans,count);
    }
    cout<<ans;
}