#include<bits/stdc++.h>
using namespace std;
int maxcons(int a[],int n,int k)
{
    int sum=0,ans=0;
    sum=accumulate(a,a+k,0);
    ans=sum;
    for(int i=k;i<n;i++)
    {
        sum-=a[i-k];
        sum+=a[i];
        ans=max(ans,sum);
    }
    return ans;
}
int main()
{
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++)
    {
    cin>>a[i];
    }
    cout<<maxcons(a,n,k);
}