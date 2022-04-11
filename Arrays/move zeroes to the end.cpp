#include<bits/stdc++.h>
using namespace std;
void zerotoend(int a[],int n)        // 1st method
{
    for(int i=0;i<n;i++)
    {
        if(a[i]==0)
        {
            int x=i;
            int j=i+1;
            while(j<n)
            {
                a[x]=a[j];
                x++;
                j++;
            }
            a[j-1]=0;
        }
    }
}
void movezeros(int a[],int n)  // 2nd method
{
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]!=0)
        {
            swap(a[i],a[count]);
            count++;
        }
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
    movezeros(a,n);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<endl;
    }
}