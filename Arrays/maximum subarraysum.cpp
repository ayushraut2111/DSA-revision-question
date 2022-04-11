#include<bits/stdc++.h>
using namespace std;
int subsum(int a[],int n)
{
    int max[n];
    max[0]=a[0];
    for(int i=1;i<n;i++)
    {
        if(max[i-1]+a[i]<=a[i])
        max[i]=a[i];
        else
        max[i]=max[i-1]+a[i];
    }
    cout<< *max_element(max,max+n);
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
    cout<< subsum(a,n);
}