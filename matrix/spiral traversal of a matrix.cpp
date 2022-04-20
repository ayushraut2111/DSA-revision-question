#include<bits/stdc++.h>
using namespace std;
void spiraltraversal(int*a[],int n,int m)
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
    else{
    int lu=0,ru=0,ll=n-1,rl=m-1;
    while(lu<=rl&&ru<=ll)
    {
        for(int i=lu;i<=rl;i++)
        {
            cout<<a[ru][i]<<" ";
        }
        lu++;
        rl--;
        for(int i=ru+1;i<=ll;i++)
        {
            cout<<a[i][rl+1]<<" ";
        }
        ru++;
        ll--;
        for(int i=rl;i>=lu;i--)
        {
            cout<<a[ll+1][i]<<" ";
        }
        for(int i=ll+1;i>=ru;i--)
        {
            cout<<a[i][lu-1]<<" ";
        }
    }
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
    spiraltraversal(a,n,m);
}