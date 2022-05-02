#include<bits/stdc++.h>
#define ll long long
using namespace std;
void stockspan(int a[],int n)
{
    int temp[n];
    temp[0]=1;
   stack<int>s;
   s.push(0);
   for(int i=1;i<n;i++)
   {
       while(!s.empty()&&a[i]>=a[s.top()])
       {
           s.pop();
       }
       if(s.empty())
       {
           temp[i]=i+1;
       }
       else
       {
           temp[i]=i-s.top();
       }
       s.push(i);
   }
    for(int i=0;i<n;i++)
    cout<<temp[i]<<endl;
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
// the idea behind solving this problem is to compare the element first from its previous element is the current element is smaller
// than its previous element then stop as we get the grater element on the left side but when the current element is greater than the 
// previous element then check with their previous element keep doind untill we get greater element than the current element.
//we are pushing index instead of te element itself because no. of consecutive days is equal to (current index)-(index of left previous)
// and if we push element then we have to run a loop again to know the index of that element 

// we keep on checking with left previouses because if current is greater than its previous than it could only be smaller from their 
// left greater only because anything falling between left greater and current's previous is also smaller than current 

