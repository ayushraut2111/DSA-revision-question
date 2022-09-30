#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(auto &x:a)cin>>x;
    unordered_set<int>s;
    int sum=0;
    for(auto x:a)
    {
        sum+=x;
        if(sum==0)
        {
            cout<<"yes";
            return 0;
        }
        if(s.find(sum)!=s.end())
        {
            cout<<"yes";
            return 0;
        }
        s.insert(sum);
    }
    cout<<"no";
}