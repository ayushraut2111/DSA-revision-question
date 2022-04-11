#include<bits/stdc++.h>
using namespace std;
#define in long long int 
int goodarray(in a[],in n,in x,in y)
{
    in c1=0,c2=0;
    for(in i=0;i<n;i++)
    {
        if(i%2==0&&a[i]!=1)
        {
            c1+=x;
        }
        else if(i%2==1&&a[i]!=0)
        {
            c1+=y;
        }
        else
        continue;

    }
    for(int i=0;i<n;i++)
    {
        if(i%2==0&&a[i]!=0)
        {
            c2+=y;
        }
        else if(i%2==1&&a[i]!=1)
        {
            c2+=x;
        }
        else
        continue;
    }
    return min(c1,c2);

}
int main()
{
    in t;
    cin>>t;
    while(t--)
    {
        in n,x,y;
        cin>>n>>x>>y;
        in a[n];
        for(int i=0;i<n;i++)
        cin>>a[i];
        cout<<goodarray(a,n,x,y)<<endl;
    }
}