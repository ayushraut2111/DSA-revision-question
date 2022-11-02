#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    priority_queue<int,vector<int>,greater<int>>pq;
    int n,k;
    cin>>n>>k;
    vector<int>v(n);
    for(auto &x:v){cin>>x;pq.push(x);}
    int count=0;
    while(!pq.empty() && pq.top()<=k)
    {
        k-=pq.top();
        pq.pop();
        count++;
    }
    cout<<count<<endl;
}