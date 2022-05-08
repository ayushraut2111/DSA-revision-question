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
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
    cin>>a[i];
    }
    cout<<largestarea(a,n);
}
// the logic behind solving this question is to first find previous on left and right side index of the element then calculate 
// how many elements are between current element and left and right side smaller because in between there are greater elements 
// so basicaly we are finding the greater elements on left and right side and then multiplying it with current element to find the 
// largest rectangle area in histogram as sides are parallel so we have to make all the elements equal as current element so 
// we have to take elements equal and then multiply