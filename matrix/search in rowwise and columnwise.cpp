#include<bits/stdc++.h>
using namespace std;
void searchrc(int *a[],int n,int m,int v)
{
    int x=0,y=m-1;
    while(x<n&&y>=0)
    {
        if(v==a[x][y])
        {
            cout<<x<<" "<<y<<endl;
            return ;
        }
        else if(v<a[x][y])
        y--;
        else
        x++;
    }
    cout<<"not found"<<endl;
    return ;
}
    int main()
{
    int n,m,v;
    cin>>n>>m>>v;
    int *a[n];
    for(int i=0;i<n;i++)
    {
        a[i]=new int[m];
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }
    searchrc(a,n,m,v);
}
