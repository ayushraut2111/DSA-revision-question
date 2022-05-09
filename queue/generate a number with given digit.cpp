#include<bits/stdc++.h>
#define ll long long
using namespace std;
void generate(vector<ll>&v,ll n,ll x,ll y)
{
    ll a[2]={x,y};
    queue<ll>q;
    v.push_back(x);
    v.push_back(y);
    q.push(x);
    q.push(y);
    n-=2;
    while(n>0)
    {
        ll x=q.front();
        q.pop();
        v.push_back(x*10+a[0]);
        q.push(x*10+a[0]);
        v.push_back(x*10+a[1]);
        q.push(x*10+a[1]);
        n=n-2;
    }
    
}
int main()
{
    vector<ll>v;
    ll x,y;
    cin>>x>>y;
    ll n;
    cin>>n;
    generate(v,n,x,y);
   for(ll i=0;i<n;i++)
   {
       cout<<v[i]<<endl;
   }
}


// to generate the digits first push both digits in a queue and then run a loop and then remove that elements from the queue and everytime
// we have to increase the digit by multiplying with 10 and adding that digits so everytime after doing this push that elements in queue and everytime
// we are pushing 2 elements so decrease n by 2

// eg. for {5 6}  => 5,6,55,56,65,66,555,556,565,566.......