#include<bits/stdc++.h>
using namespace std;
bool zerosubarray(int a[],int n)
{
    unordered_set<int>s;
    int presum=0;
    for(int i=0;i<n;i++)     
    {
        presum+=a[i];
        if(presum==0||a[i]==0)
        return true;
        if(s.find(presum)!=s.end())
        return true;
        else
        s.insert(presum);
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
    zerosubarray(a,n)?cout<<"yes":cout<<"no";
}

// to solve this lets take a array and take any big subarray say it A and then break it in two part B and C so if the subarray C
// sum is 0 then B is equal to A because A=B+C so we find the sum till that element and if that sum  is present in hash table 
// then we can say that there is a subarray whose sum is zero 