#include<bits/stdc++.h>
using namespace std;
int getlarge(vector<int>v)
{
     int res=0;
    int max=0;
    int n=v.size();
    for(int i=0;i<n;i++)
    {
        if(v[i]>max)
        {
            max=v[i];
            res=i;
        }
    }
    return res;
}
int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    int lar=getlarge(v);             // first find the largest element and then find the largest among the remaining element
    int res=-1;                      // if no second largest number is there then do not update result 
    int max=0; 
    for(int i=0;i<n;i++)
    {
        if(v[i]!=v[lar]){
        if(v[i]>max)
        {
            max=v[i];
            res=i;
        }
    }
    }
    if(res==-1)
    cout<<"no second largest number"<<endl;
    else
    cout<<v[res]<<endl;

}