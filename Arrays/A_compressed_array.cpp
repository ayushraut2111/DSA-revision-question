#include<bits/stdc++.h>
using namespace std;
bool cmp(vector<int>a,vector<int>b)
{
    return a.size()<b.size();

}
void subarray(int a[],int n,vector<vector<int>>&v,vector<int>&x,int i)
{
    if(i==n){
        v.push_back(x);
        return ;   
    }
    subarray(a,n,v,x,i+1);
    x.push_back(a[i]);
    subarray(a,n,v,x,i+1);
    x.pop_back();
   
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
       int n;
       cin>>n;
       int a[n];
       vector<int>x;
       for(int i=0;i<n;i++)
       {
       cin>>a[i];
       }
       vector<vector<int>>v;
       subarray(a,n,v,x,0);
       sort(v.begin(),v.end(),cmp);
       vector<vector<int>>z;
    //    z.push_back(v[0]);
    //    for(int i=0;i<v.size();i++)
    //    {
    //        if(v[i]!=z[z.size()-1])
    //        {
    //            z.push_back(v[i]);
    //        }
    //    }
       for(auto m:v)
       {
           for(auto q: m)
           {
               cout<<q<<" ";
           }
           cout<<endl;
       }
    }
}