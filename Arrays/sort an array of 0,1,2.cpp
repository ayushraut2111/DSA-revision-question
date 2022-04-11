#include<bits/stdc++.h>
using namespace std;
void sortarr(int arr[],int n)
{
    int low=0;
    int mid=0;
    int high=n-1;
    for(int i=0;i<n;i++)
    {
        if(mid<=high){
        if(arr[i]==0)
        {
            swap(arr[low],arr[mid]);
            low++;
            mid++;
        }
        else 
        if(arr[i]==2)
        {
            swap(arr[mid],arr[high]);
            high--;
        }
        else
        mid++;
    }
    }
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sortarr(arr,n);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i];
    }
}