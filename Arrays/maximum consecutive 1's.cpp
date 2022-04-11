#include<bits/stdc++.h>
using namespace std;
int maxone(int a[],int n)
{
    int index=0;
    int ans=0;
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]==0)
        {
            ans=max(ans,count);
            count=0;
        }
        else
        count++;
    }
    ans=max(ans,count);
    return ans;
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
    cout<<maxone(a,n);
}