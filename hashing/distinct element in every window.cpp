#include<bits/stdc++.h>
using namespace std;
void countwindow(int a[],int n,int k)
{
    vector<int>v;
    unordered_map<int,int>mp;
    for(int i=0;i<k;i++)
    {
        if(mp.find(a[i])==mp.end())
        {
            mp[a[i]]=1;
        }
        else
        mp[a[i]]++;
    }
    v.push_back(mp.size());
    for(int i=k;i<n;i++)
    {
        mp[a[i-k]]--;
        if(mp[a[i-k]]==0)
        {
            mp.erase(a[i-k]);
        }
        if(mp.find(a[i])==mp.end())
        {
            mp[a[i]]=1;
        }
        else
        mp[a[i]]++;
        v.push_back(mp.size());
    }
    for(auto x:v)
    {
        cout<<x<<" ";
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
    int k;
    cin>>k;
    countwindow(a,n,k);
}

// to solve this question first find the distinct element in the first k window then slide window 1 position ahead and then decrease the first element of the previous window
// and check if it is 0 then remove and then push the current element in the hashtable and then print the size of the map as it is the no. of distinct element in the current 
// window