#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{

    priority_queue<int>q; // max priority queue
    priority_queue<int,vector<int>,greater<int>>pq;    //minimum priority queue
    pq.push(2);
    pq.push(4);
    while(!pq.empty())
    {
        cout<<pq.top()<<endl;
        pq.pop();
    }
}