#include<bits/stdc++.h>
using namespace std;
int longsubarray(int a[],int n,int k)
{
    int presum=0;
    int res=0;
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++)
    {
        if(a[i]==k)
        {
            res=1;
            res=max(res,1);
        }
        presum+=a[i];
        if(presum==k)
        {
            res=max(res,i+1);
        }
        if(mp.find(presum)==mp.end())
        {
            mp[presum]=i;
        }
        if(mp.find(presum-k)!=mp.end())
        {
            res=max(res,i-mp[presum-k]);
        }
    }
    return res;
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
    cout<<longsubarray(a,n,k);
}

// the idea is to calculate the prefix sum of the elements till that element and keep checking if the current prefix sum is equal to the 
//given sum then update the result and then check if the prefix sum is not yet in the map then push it into the map, push only the first
// time because the left one will give us the longest subarray as we are moving right so after that check if we find the prefix sum
// minus sum if yes then update result with given index minus the index of that prefix sum-(given sum)