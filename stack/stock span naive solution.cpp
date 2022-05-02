#include<bits/stdc++.h>
#define ll long long
using namespace std;
void stockspan(int a[],int n)  // time complexity of this problem is 0(n^2)
{
    int temp[n];
    temp[0]=1;
    for(int i=1;i<n;i++)
    {
        int count=1;
        for(int j=i-1;j>=0;j--)
        {
            if(a[j]<a[i])
            {
                count++;
            }
            else
            break;
        }
        temp[i]=count;
    }
    for(int i=0;i<n;i++)
    {
        cout<<temp[i]<<endl;
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
    stockspan(a,n);
}

// this problem states that we have given the prices of a stock and we have to find the consecutive no. of days including current day 
// the price of the stock is less than equal to the current day 