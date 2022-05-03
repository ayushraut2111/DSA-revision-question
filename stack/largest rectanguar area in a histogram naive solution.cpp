#include<bits/stdc++.h>
#define ll long long
using namespace std;
int largestarea(int a[],int n)
{
    int res=0;
    for(int i=0;i<n;i++)
    {
        int curr=a[i];
        for(int j=i-1;j>=0;j--)   // calculating the continuous equal or greater size element than current  in left side
        {
            if(a[j]>=a[i])      // if it is greater and equal then add in result else stop
            curr+=a[i];
            else
            break;
        }
        for(int j=i+1;j<n;j++)  // calculating the continuous equal or greater size element than current  in right side
        {
            if(a[j]>=a[i])      // if it is greater and equal then add in result else stop
                curr+=a[i];
                else
                break;  
        }
        res=max(res,curr);   // after calculation update result 
    }
    return res;
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
    cout<<largestarea(a,n);
}

// the idea behind is to for a current element consider every left and right element of same size if the elements is greater or 
// same size and stop if we get the smaller element because we want largest rectangle area which is obviously be continuous as the 
// sizes are parallel so we have to take same size as current element for left and right element do this for for every element for
// left side and right side both and after calculating for every element update the result