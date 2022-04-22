#include<bits/stdc++.h>
using namespace std;
int longestcons(int a[],int n)
{
    unordered_set<int>s;
    int res=0,curr;
    for(int i=0;i<n;i++)
    {
        s.insert(a[i]);
    }
    for(int i=0;i<n;i++)
    {
        if(s.find(a[i]-1)==s.end())
        {
            curr=1;
        while(s.find(a[i]+curr)!=s.end())
        {
            curr++;
        }
        }
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
    cout<<longestcons(a,n);
}
// idea behind solving this question is to intialse every element in hash table and then checking for every element if their one
// previous element is present in hashtable or not if not then keep incrementing untill we keep finding its next element
// stop when we dont find and update the result do this for every element whose previous element is not present