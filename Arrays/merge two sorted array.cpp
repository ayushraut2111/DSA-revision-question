#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n,m;
  cin>>n>>m;
  int a[n],b[m];
  for(int i=0;i<n;i++)
  {
      cin>>a[i];
  }
  for(int i=0;i<m;i++)
  {
      cin>>b[i];
  }
  vector<int>v;
  int l=0,h=0;
  while(l<n&&h<m)
  {
      if(a[l]<=b[h])
      {
          v.push_back(a[l]);
          l++;
      }
      else
      {
          v.push_back(b[h]);
          h++;
      }
  }
  if(l==n)
  {
      for(int i=h;i<m;i++)
      {
          v.push_back(b[i]);
      }
  }
  else
  {
      for(int i=h;i<n;i++)
      {
          v.push_back(a[i]);
      }
  }
  for(auto x:v)
  cout<<x<<endl;

}