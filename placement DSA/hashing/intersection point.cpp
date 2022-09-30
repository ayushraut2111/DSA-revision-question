#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>a(n),b(n);
    for(auto &x:a)cin>>x;
    for(auto &x:b)cin>>x;
    unordered_set<int>s;
    for(auto x:b)
    s.insert(x);
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(s.find(a[i])!=s.end())
        {
            s.erase(a[i]);
            count++;
        }
    }
    cout<<count<<endl;
}