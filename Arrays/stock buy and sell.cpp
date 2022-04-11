#include<bits/stdc++.h>
using namespace std;
int stock(int a[],int n)
{
    int profit=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]>a[i-1])
        {
            profit+=a[i]-a[i-1];
        }
    }
    return profit;
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
    cout<<stock(a,n);
}