#include<bits/stdc++.h>
#define ll long long
using namespace std;
void nextgreater(int a[],int n)
{
    int temp[n];
    temp[n-1]=-1;
    stack<int>s;
    s.push(a[n-1]);
    for(int i=n-2;i>=0;i--)
    {
        while(!s.empty()&&a[i]>=s.top())
        {
            s.pop();
        }
        if(s.empty())
        {
            temp[i]=-1;
        }
        else
        {
            temp[i]=s.top();
        }
        s.push(a[i]);
    }
    for(int i=0;i<n;i++)
    {
        cout<<temp[i]<<endl;
    }
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
    cin>>a[i];
    }
    nextgreater(a,n);
}