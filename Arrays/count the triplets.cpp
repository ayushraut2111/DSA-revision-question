#include<bits/stdc++.h>
using namespace std;
int countthetriplets(int a[],int n)
{
    unordered_set<int>s;
    for(int i=0;i<n;i++)
    s.insert(a[i]);
    int count=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(s.find(a[i]+a[j])!=s.end())
            {
                count++;
            }
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
    cout<<countthetriplets(a,n);
}