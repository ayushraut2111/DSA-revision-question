#include<bits/stdc++.h>
using namespace std;
void setmatrix(vector<int>a[],int n,int m)
{
    
    vector<pair<int,int>>c;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(a[i][j]==0)
            {
                c.push_back({i,j});
            }
        }
    }
    for(auto x: c)
    {
        for(int k=0;k<m;k++)
        a[x.first][k]=0;
        for(int k=0;k<n;k++)
        a[k][x.second]=0;
    }

}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>v[n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            int x;
            cin>>x;
            v[i].push_back(x);
        }
    }
    setmatrix(v,n,m);
    for(auto x:v)
    {
        for(auto y:x)
        {
            cout<<y<<" ";
        }
        cout<<endl;
    }

}