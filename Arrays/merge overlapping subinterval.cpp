#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> oversub(vector<pair<int,int>>v,int n)
{
    sort(v.begin(),v.end());
    vector<pair<int,int>>x;
    pair<int,int> p={v[0].first,v[0].second};
    if(n==1)
    {
        x.push_back(p);
    }
    for(int i=1;i<n;i++)
    {
        if(v[i].first<=p.second&&v[i].second>p.second)
        {
            p.second=v[i].second;
        }
        if((v[i].first>p.second&&v[i].second>p.second)||i==n-1)
        {
            x.push_back(p);
            p={v[i].first,v[i].second};
             if(i==n-1)
             {
                if(p.first>x[x.size()-1].second&&p.second>x[x.size()-1].second)
                {
                    x.push_back(p);
                }
             }
        }

    }
    return x;
}
int main()
{
    vector<pair<int,int>>v;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        v.push_back({x,y});
    }
    vector<pair<int,int>>x=oversub(v,n);
    for(auto y:x)
    {
        cout<<y.first<<" "<<y.second<<endl;
    }
}