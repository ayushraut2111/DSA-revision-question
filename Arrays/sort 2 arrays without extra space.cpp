#include<bits/stdc++.h>
using namespace std;
void sortarr(int arr1[],int arr2[],int n,int m)
{
    int i=0,j=0;
    while(i<n&&j<m)
    {
        if(arr2[j]<arr1[i])
        {
            swap(arr1[i],arr2[j]);
            i++;
            sort(arr2,arr2+m);
        }
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    int arr1[n],arr2[m];
    for(int i=0;i<n;i++)
    {
        cin>>arr1[i];
    }
    for(int i=0;i<m;i++)
    {
        cin>>arr2[i];
    }
    sortarr(arr1,arr2,n,m);
    for(int i=0;i<n;i++)
    {
        cout<<arr1[i]<<endl;
    }
    for(int i=0;i<m;i++)
    {
        cout<<arr2[i]<<endl;
    }
}