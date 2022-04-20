#include<bits/stdc++.h>
using namespace std;
void snakeprint(int **a,int n,int m)
{
    for(int i=0;i<n;i++)
    {
        if(i%2!=0)
        {
            for(int j=m-1;j>=0;j--)
            {
                cout<<a[i][j]<<" ";
            }
        }
        else
        {
            for(int j=0;j<m;j++)
            {
                cout<<a[i][j]<<" ";
            }
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
    snakeprint(a,n,m);
}