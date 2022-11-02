#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    priority_queue<int>pq;
    int n,k;
    cin>>n>>k;
    vector<int>v(n);
    for(auto &x:v){cin>>x;pq.push(x);}
    int ans;
    while(k--)
    {
        ans=pq.top();
        pq.pop();
    }
    cout<<ans;
}