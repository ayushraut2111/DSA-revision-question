#include<bits/stdc++.h>
using namespace std;

int combination(int n,int r)
{
    int count=1;
    for(int i=n;i>n-r;i--)
    {
        count*=i;
    }
    int count1=1;
    for(int i=1;i<=r;i++)
    count1*=i;
    return count/count1;
}
vector<vector<int>> pascal(int n)
{
    vector<vector<int>>v;
    for(int i=1;i<=n;i++)
    {
        vector<int>f;
        for(int j=1;j<=i;j++)
        {
            f.push_back(combination(i-1,j-1));

        }
        v.push_back(f);
    }
    return v;
}
int main()
{
    int n;
    vector<vector<int>>v=pascal(7);
    for(auto x:v)
    {
        for(auto y:x)
        {
            cout<<y<<" ";
        }
        cout<<endl;
    }
}