#include<bits/stdc++.h>
using namespace std;
int maxsum(int a[],int n)
{
    int maxi[n];
    maxi[0]=a[0];
    for(int i=1;i<n;i++)
    {
        maxi[i]=max(maxi[i-1]+a[i],a[i]);
    }
    return *max_element(maxi,maxi+n);
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
    cout<<maxsum(a,n);
}