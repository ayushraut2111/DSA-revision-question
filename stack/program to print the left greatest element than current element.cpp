#include<bits/stdc++.h>
#define ll long long
using namespace std;
void leftgreater(int a[],int n)
{
    int temp[n];
    temp[0]=a[0];
    stack<int>s;
    s.push(a[0]);
    for(int i=1;i<n;i++)
    {
        while(!s.empty()&&a[i]>=s.top())
        {
            s.pop();
        }
        if(s.empty())
        {
            temp[i]=a[i];
        }
        else{
            temp[i]=s.top();
        }
        s.push(a[i]);
    }
    for(int i=0;i<n;i++)
    cout<<temp[i]<<endl;
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
    leftgreater(a,n);
}

// the idea behind is to first compare the element with its prev if it is smaller then take the left prev as that element and
// if current element is greater than prev element then check with its prev and so on untill we found the greater element if 
// the stack is empty that means there is no greater element so print that number itself