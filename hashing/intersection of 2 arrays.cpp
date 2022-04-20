#include<bits/stdc++.h>
using namespace std;
int intersection(int a[],int n,int b[],int m)
{
    unordered_set<int>s1,s2;
    for(int i=0;i<n;i++)
    {
        s1.insert(a[i]);
    }
    for(int i=0;i<m;i++)
    {
        s2.insert(b[i]);
    }
    int count=0;
    for(auto it=s1.begin();it!=s1.end();it++)
    {
        if(s2.find(*it)!=s2.end())
        {
            count++;
        }
    }
    return count;
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
    int m;
    cin>>m;
    int b[m];
    for(int i=0;i<m;i++)
    {
    cin>>b[i];
    }
    cout<<intersection(a,n,b,n);
}