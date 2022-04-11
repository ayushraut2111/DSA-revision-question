#include<bits/stdc++.h>
using namespace std;
bool givensum(int a[],int n,int sum)
{
    int temp=sum,i=0;
    int k=0;
    while(k<sum&&i<n)
    {
        k+=a[i];
        i++;
    }
    if(k==sum)
    return true;
    if(k<sum)
    return false;
    temp=sum;
    for(int j=0;j<i;j++)
    {
        k-=a[j];
        if(k==sum)
        return true;
    }
    return false;
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
    givensum(a,n,k)?cout<<"yes":cout<<"no";
}

//if all the inputs are positive then we can traverse the array untill we found the sum or our ans is greater
// once we found our ans then we keep on subtracting from the beginning if we found our sum then return true else return false