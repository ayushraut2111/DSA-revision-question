#include<bits/stdc++.h>
using namespace std;
void printboundary(int **a,int n,int m)
{
    if(n==1)
    {
        for(int i=0;i<m;i++)
        {
            cout<<a[0][i]<<" ";
        }
    }
    else if(m==1)
    {
        for(int i=0;i<n;i++)
        {
            cout<<a[i][0]<<" ";
        }
    }
    else
    {
        for(int i=0;i<m;i++)
        {
            cout<<a[0][i]<<" ";
        }
        for(int i=1;i<n;i++)
        {
            cout<<a[i][m-1]<<" ";
        }
        for(int i=m-2;i>=0;i--)
        {
            cout<<a[n-1][i]<<" ";
        }
        for(int i=n-2;i>=1;i--)
        {
            cout<<a[i][0]<<" ";
        }
    }
}
int main()
{
    int **a;
    int n,m;
    cin>>n>>m;
    a=new int*[n];
    for(int i=0;i<n;i++)
    {
        a[i]=new int[m];
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }
    printboundary(a,n,m);
}