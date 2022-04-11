#include<bits/stdc++.h>
using namespace std;
bool checksort(int a[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        int j=i+1;
        if(a[j]<a[i])
        return false;
    }
    return true;
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    if(checksort(a,n)==true)
    cout<<"the array is sorted";
    else
    cout<<"the array is not sorted";
}