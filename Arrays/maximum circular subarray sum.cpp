// max circular subarray sum include normal max subarray sum and the subarray including normal subarray and the first index onward so to find this first find 
// the normal subarray sum and then for the second part to get the circular sum we have to subtract the minimum subarray sum from the minimum subarray sum
// to get the minimum subarray sum just inverse the array   and then find the max sum and then add it in total sum to get the max circular sum and for the result 
// return the max from both ((basically for the second part we are subtracting minimun subarray sum from  the total sum to get the max circular sum))

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
int circlesum(int a[],int n)
{
    int x=maxsum(a,n);
    if(x<0)
    return x;
    int tsum=0;
    for(int i=0;i<n;i++)
    {
        tsum+=a[i];
        a[i]=-a[i];
    }
    int temp=tsum+maxsum(a,n);
    return max(x,temp);

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
    cout<<circlesum(a,n);
}