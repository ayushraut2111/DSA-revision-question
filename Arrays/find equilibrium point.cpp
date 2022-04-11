#include<bits/stdc++.h>
using namespace std;
bool equilibrium(int a[],int n)
{
    int presum[n];
    presum[0]=a[0];
    for(int i=1;i<n;i++)
    {
        presum[i]=presum[i-1]+a[i];
    }
    int suffixsum[n];
    suffixsum[n-1]=a[n-1];
    for(int i=n-2;i>=0;i--)
    {
        suffixsum[i]=suffixsum[i+1]+a[i];
    }
    for(int i=0;i<n;i++)
    {
        if(presum[i]==suffixsum[i])
        return true;
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

    equilibrium(a,n)?cout<<"yes":cout<<"no";
    
}

// equilibrium point means the sum of left side of a subarray is equal to the right side of the subarray for any number
// so to find this first find the prefix sum of all the numbers and then find the suffix sum of the number and then check whether for any number prefix and suffix
// sum is equal or not if it is equal then return true else return false