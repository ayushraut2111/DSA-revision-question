// if we have given k largest or k smallest then we should always use heaps... for the identification of max or min heap to be used
// if we have k largest then use min heap of size k as after popping min element everytime we have min element at the top so the kth largest will be at the top as the largest will be at the last os the heap
// same with the k minimum we have to make the max heap of size k


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
    priority_queue<int>pq;
    for(int i=0;i<k;i++)
    {
        pq.push(a[i]);
    }
    for(int i=k;i<n;i++)
    {
        pq.push(a[i]);
        pq.pop();  // by popping the max element everytime we have only the k smalest element remaining at the end
    }
    cout<<pq.top()<<endl;
}