#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int r,m;
    bool visited[n+1];
      for(int i=0;i<n+1;i++)
      visited[i]=false;
      for(int i=0;i<n;i++)
      {
          if(visited[arr[i]]==true)
          r=arr[i];
          else
          visited[arr[i]]=true;
      }
      for(int i=1;i<n+1;i++)
      if(visited[i]==false)
      m=i;
    cout<<m<<" "<<r<<endl;
}