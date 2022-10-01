#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int  n,k;
    cin>>n>>k;
    vector<int>v[k+1];
    while(k--)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
    }
    int count=0;
    int i=1;
    for(auto x:v)
    {
        for(int j=0;j<x.size();j++)
        {
            if(x[j]==i)
            count++;
        }
        i++;
    }
    cout<<count<<endl;

}