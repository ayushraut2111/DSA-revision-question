#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    for(auto &x:a)cin>>x;
    unordered_set<int>s;
    for(auto x:a)
    {
        if(s.find(k-x)==s.end())
        {
            s.insert(x);
        }
        else
        {
            cout<<"yes"<<endl;
            return 0;
        }
    }
    cout<<"no";
}