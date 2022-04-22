#include<bits/stdc++.h>
using namespace std;
void morethan(int a[],int n,int k)
{
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++)
    {
        mp[a[i]]++;
    }
    for(auto x:mp)
    {
       if(x.second>(n/k))
       {
           cout<<x.first<<endl;
       }
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
    int k;
    cin>>k;
    morethan(a,n,k);
}