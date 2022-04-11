#include<bits/stdc++.h>
using namespace std;
void sortar(vector<int>&nums)
{
     int z=0,o=0,t=0;
        for(auto x:nums)
        {
            if(x==0)
                z++;
            else if(x==1)
                o++;
            else
                t++;
        }
        for(int i=0;i<z;i++)
            nums[i]=0;
        for(int i=z;i<z+o;i++)
            nums[i]=1;
         for(int i=z+o;i<z+o+t;i++)
            nums[i]=2;
}
int main()
{
  int n;
  cin>>n;
  vector<int>nums;
  for(int i=0;i<n;i++)
  {
      int x;
      cin>>x;
      nums.push_back(x);
  }
sortar(nums);
  for(auto x:nums)
  cout<<x<<endl;
}

