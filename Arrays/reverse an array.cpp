#include<bits/stdc++.h>
using namespace std;
void reversearray(int a[],int n)
{
    int l=n-1;
    for(int i=0;i<n/2;i++)
    {
        swap(a[i],a[n-1-i]);
    }
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    reversearray(a,n);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<endl;
    }
}