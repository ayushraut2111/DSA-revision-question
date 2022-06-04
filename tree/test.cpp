#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    vector<int>v(3);
    v[0]=1;
    v[1]=2;
    v[2]=3;
    if(find(v.begin(),v.end(),2)!=v.end())
    {
        cout<<"found at"<<find(v.begin(),v.end(),2)-v.begin();
    }
    else
    cout<<"not found"<<endl;
}