#include<bits/stdc++.h>
using namespace std;
int numberofpairs(int n)
{
    int count=0;
    if(n==1)
    return 1;
    for(int i=1;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
            count+=2;   
        }
    }
    int x=pow(int(sqrt(n)),2);
    if(x==n)
    return count-1;
    return count;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<numberofpairs(n)<<endl;
    }
}