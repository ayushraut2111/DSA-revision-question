#include<bits/stdc++.h>
using namespace std;
void transpose(int *a[],int n,int m)
{
    for(int i=0;i<n;i++)           
    {
        for(int j=0;j<=i;j++)
        {
            swap(a[i][j],a[j][i]);
        }
    }
}
void rotate90(int *a[],int n,int m)  // to rotate a matrix 90 degree first find the transpose of a matrix and then swap the value of 1st
{                                    // row with last row then 2nd row with 2nd last row and so on do this n/2 by this all the rows gets swapped
    transpose(a,n,m);
    for(int i=0;i<n/2;i++)
    {
        for(int j=0;j<m;j++)
        {
            swap(a[i][j],a[n-1-i][j]);
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
    rotate90(a,n,m);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}