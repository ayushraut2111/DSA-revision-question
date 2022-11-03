#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++)
    {
    cin>>a[i];
    }
    priority_queue<int,vector<int>,greater<int>>pq;
    for(int i=0;i<=k;i++)    //we have taken the size of heap as k+1 as for the previous elements of a current elements priority queue is maintained so ith element can only come in range k+1 after the i
    {
        pq.push(a[i]);
    }
    vector<int>v;
    for(int i=k+1;i<n;i++)    
    {
        v.push_back(pq.top());
        pq.pop();
        pq.push(a[i]);
    }
    while(!pq.empty())
    {
        v.push_back(pq.top());
        pq.pop();
    }
    for(auto x:v)cout<<x<<endl;
}