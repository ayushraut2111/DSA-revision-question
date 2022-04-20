#include<bits/stdc++.h>
using namespace std;
bool pairsum(int a[],int n,int k)
{
    unordered_set<int>s;
    for(int i=0;i<n;i++)
    {
        if(s.find(k-a[i])!=s.end())
        {
            return true;
        }
        else
        s.insert(a[i]);
    }
    return false;
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
    pairsum(a,n,k)?cout<<"yes":cout<<"no";
}