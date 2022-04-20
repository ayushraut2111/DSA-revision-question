#include<bits/stdc++.h>
using namespace std;
bool givensum(int a[],int n,int k)
{
    int b[n];
    b[0]=a[0];
    for(int i=1;i<n;i++)
    {
        b[i]=b[i-1]+a[i];
    }
    unordered_set<int>s;
    for(int i=0;i<n;i++)
    {
        if(b[i]==0||s.find(b[i]-k)!=s.end())
        {
            return true;
        }
        else
        {
            s.insert(b[i]);
        }
    }
    return false;
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
    givensum(a,n,k)?cout<<"yes":cout<<"no";
}

// to solve this we calculate the prefix sum till the last element for all the elements and then we find if till prefix sum of any 
// element - that sum is present in hashtable then return yes