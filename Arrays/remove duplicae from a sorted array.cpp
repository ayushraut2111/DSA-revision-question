#include<bits/stdc++.h>
using namespace std;
void removeduplicate(int a[],int n,int &count)
{
    int x=a[0];
    for(int i=0;i<n-1;i++)
    {
        int j=i+1;
        if(x==a[j])
        {
            x=a[j];
            a[j]=-1;
        }
        else{
        count++;
        x=a[j];
        }
    }
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    int count=1;
    removeduplicate(a,n,count);
    cout<<count<<endl<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<endl;
    }
}