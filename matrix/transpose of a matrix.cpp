#include<bits/stdc++.h>
using namespace std;
void transpose(int *a[],int n,int m)
{
    int *t[n];
    for(int i=0;i<n;i++)
    {
        t[i]=new int[m];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            t[j][i]=a[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<t[i][j]<<" ";
        }
        cout<<endl;
    }
}
void transpose1(int *a[],int n,int m)    // tranpose by swapping the value of a[i][j] and a[j][i] but we traverse only for half of the matrix because if we traverse 
{
    for(int i=0;i<n;i++)                // for the full matrix then ou mtrix become same as previous
    {
        for(int j=0;j<=i;j++)
        {
            swap(a[i][j],a[j][i]);
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    int *a[n];
    for(int i=0;i<n;i++)
    {
        a[i]=new int[m];
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }
    transpose(a,n,m);
    cout<<endl;
    transpose1(a,n,m);
}