#include<bits/stdc++.h>
#define ll long long
using namespace std;
int largestarea(int a[],int n)
{
    int left[n],right[n];
    stack<int>s1,s2;
    s1.push(0);
    left[0]=-1;
    for(int i=1;i<n;i++)
    {
        while(!s1.empty()&&a[i]<=a[s1.top()])
        {
            s1.pop();
        }
        if(s1.empty())
        {
            left[i]=-1;
        }
        else
        {
            left[i]=s1.top();
        }
        s1.push(i);
    }
    right[n-1]=n;
    s2.push(n-1);
    for(int i=n-2;i>=0;i--)
    {
        while(!s2.empty()&&a[i]<=a[s2.top()])
        {
            s2.pop();
        }
        if(s2.empty())
        {
            right[i]=n;
        }
        else
        {
            right[i]=s2.top();
        }
        s2.push(i);
    }
    int res=0;
    for(int i=0;i<n;i++)
    {
        int curr=a[i];
        curr+=(i-left[i]-1)*a[i];
        curr+=(right[i]-i-1)*a[i];
        res=max(res,curr);
    }
    return res;
}
int largestrectangle(int **a,int n,int m)
{
    int res=0;
    for(int i=0;i<n;i++)
    {
        int curr=largestarea(a[i],m);
        res=max(res,curr);
        if(i!=n-1){
        for(int j=0;j<m;j++)
        {
            if(a[i+1][j]!=0){
           a[i+1][j]+=a[i][j];
            }
        }
    }
    }
    return res;
}
int main()
{
    int n,m;
    cin>>n>>m;
    int **a;
    a=new int*[n];
    for(int i=0;i<n;i++)
    {
        a[i]=new int[m];
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }
    cout<<largestrectangle(a,n,m);
}
// the idea behind solving this problem is to start from the 1st row and pass that row to function which calculates largest rectange area in a 
// histogram and then update the ans and then come to the next row and add the upper row and dont add upper row if the eleement is 0
// keep doing this until we reach the last row keep calling the function after adding the upper row and keep on updating ans with 
//every function call