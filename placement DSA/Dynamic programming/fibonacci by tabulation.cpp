#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int n;
    cin>>n;
    // vector<int>dp(n+1);  // this is taking space complexity also o(n)
    // dp[0]=0;dp[1]=1;
    // for(int i=2;i<=n;i++)dp[i]=dp[i-1]+dp[i-2];   
    // cout<<dp[n]<<endl;

    // we can optimise it as constant space complexity as it requirs only 2 prev datas
    int prev=0,prev1=1;
    for(int i=2;i<=n;i++)
    {
        int x=prev+prev1;
        
        prev=prev1;
        prev1=x;
    }
    cout<<prev1<<endl;

}
